"""
Script Name: leetcode_workflow.py
Description: This script automates the process of creating LeetCode problems in multiple programming languages.
"""

import os
import sys
import requests
from datetime import datetime
from bs4 import BeautifulSoup

BASE_DIR = os.path.join(os.getcwd(), "algorithms")

# LeetCode problem API endpoint
API_URL = "https://leetcode.com/graphql"

QUERY = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    boundTopicId
    title
    titleSlug
    content
    translatedTitle
    translatedContent
    isPaidOnly
    difficulty
    likes
    dislikes
    isLiked
    similarQuestions
    contributors {
      username
      profileUrl
      avatarUrl
      __typename
    }
    langToValidPlayground
    topicTags {
      name
      slug
      translatedName
      __typename
    }
    companyTagStats
    codeSnippets {
      lang
      langSlug
      code
      __typename
    }
    stats
    hints
    solution {
      id
      canSeeDetail
      __typename
    }
    status
    sampleTestCase
    metaData
    judgerAvailable
    judgeType
    mysqlSchemas
    enableRunCode
    enableTestMode
    envInfo
    __typename
  }
}
"""

comment_symbols = {
    "javascript": "*",
    "typescript": "*",
    "python3": "#",
    "java": "*",
    "cpp": "*",
    "golang": "*",
    "mysql": "--",
    "postgresql": "--",
    "bash": "#",
}

languages = ["javascript", "typescript", "python3", "java", "cpp", "golang", "mysql", "postgresql", "bash"]

# Headers for the request
def get_headers(title_slug):
    return {
        'Origin': 'https://leetcode.com',
        'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'zh-CN,zh;q=0.9,und;q=0.8,en;q=0.7',
        'Cookie': '__cfduid=dae082e425ee3916c04a5170b832e268e1524142659; _ga=GA1.2.1432146910.1524142661; _gid=GA1.2.650843898.1529736240; csrftoken=iSKedVXxGDkBBXbP9chsyXhbIrRedF7iw2EMRZiemtzKD8vjHSWZJKkKQVIwZKp7; __atuvc=2%7C25; __atuvs=5b2ded02313c83c4001; _gat=1',
        'x-csrftoken': 'iSKedVXxGDkBBXbP9chsyXhbIrRedF7iw2EMRZiemtzKD8vjHSWZJKkKQVIwZKp7',
        'Content-Type': 'application/json',
        'Accept': '*/*',
        'Cache-Control': 'no-cache',
        'Authority': 'leetcode.com',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.87 Safari/537.36',
        'Referer': f'https://leetcode.com/problems/{title_slug}/description/'
    }


def fetch_problem(title_slug):
    # Prepare the request payload
    payload = {
        "operationName": "questionData",
        "query": QUERY,
        "variables": {
            "titleSlug": title_slug
        }
    }

    # Make the request
    response = requests.post(API_URL, json=payload, headers=get_headers(title_slug))
    return response.json()["data"]["question"]


def create_template_header(problem, comment_symbol):
    hints = '\n'.join(f' {comment_symbol} {hint}' for hint in problem.get('hints', []))
    topic_tags = ', '.join(tag['name'] for tag in problem.get('topicTags', []))

    template_headers = {
        "*": f"""
/**
 * Title: {problem['title']}
 * CreateTime: {datetime.now().strftime("%Y-%m-%d")}
 * Difficulty: {problem['difficulty']}
 * Likes: {problem['likes']}
 * Dislikes: {problem['dislikes']}
 * Topic Tags: {topic_tags}
 * 
 * Problem description:
{html_to_text(problem['content'], "*")}
 *
 * Hints: 
{hints}
 */
""",
        "#": f"""
# {problem['title']}
# {datetime.now().strftime("%Y-%m-%d")}
# Difficulty: {problem['difficulty']}
# Likes: {problem['likes']}
# Dislikes: {problem['dislikes']}
# Topic Tags: {topic_tags}
#
# Problem description:
# {html_to_text(problem['content'], "#")}
#
# Hints: 
{hints}
""",
        "--": f"""
-- {problem['title']}
-- {datetime.now().strftime("%Y-%m-%d")}
-- Difficulty: {problem['difficulty']}
-- Likes: {problem['likes']}
-- Dislikes: {problem['dislikes']}
-- Topic Tags: {topic_tags}
--
-- Problem description:
-- {html_to_text(problem['content'], "--")}
--
-- Hints: 
{hints}
"""
    }
    return template_headers.get(comment_symbol, "*")


def create_template_body(problem, language):
    code_snippets_list = problem['codeSnippets']
    code_snippets_dict = {}
    for code_snippet in code_snippets_list:
        code_snippets_dict[code_snippet['langSlug']] = code_snippet['code']
    return html_to_text(code_snippets_dict.get(language), comment_symbol="*", content_type="body")


def html_to_text(html_content, comment_symbol="*", content_type="header"):
    # 创建BeautifulSoup对象，解析HTML内容
    soup = BeautifulSoup(html_content, 'html.parser')

    # 获取纯文本内容，不包括格式
    text = soup.get_text(separator="")
    lines = text.splitlines()
    commented_text = ""

    if (content_type == "header"):
        commented_text = '\n'.join(f' {comment_symbol} {line}' for line in lines)
    else:
        commented_text = '\n'.join(f'{line}' for line in lines)

    return commented_text


def create_template(problem, language):
    # Define templates for different languages
    template_header = create_template_header(problem, comment_symbols.get(language))
    print(template_header)
    template_body = create_template_body(problem, language)
    print(template_body)
    return template_header + '\n' + template_body


def save_problem(language, title_slug):
    if language not in languages:
        print("Unsupported language:", language)
        print("Supported languages:", languages)
        sys.exit(1)

    # Fetch problem details
    problem = fetch_problem(title_slug)

    # Create directory for the problem
    problem_dir = os.path.join(BASE_DIR, language, title_slug)
    os.makedirs(problem_dir, exist_ok=True)

    # Create template for the specified language
    template = create_template(problem, language)

    if template:
        file_ext = language
        if language == "cpp":
            file_ext = "cpp"
        elif language == "bash":
            file_ext = "sh"
        elif language == "javascript":
            file_ext = "js"
        elif language == "typescript":
            file_ext = "ts"
        elif language == "python3":
            file_ext = "py"
        elif language == "mysql":
            file_ext = "sql"
        elif language == "postgresql":
            file_ext = "sql"
        elif language == "java":
            file_ext = "java"
        elif language == "golang":
            file_ext = "sql"

        file_path = os.path.join(problem_dir, f"{title_slug}.{file_ext}")
        with open(file_path, "w") as f:
            f.write(template)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python leetcode_workflow.py <language> <title_slug>")
        sys.exit(1)

    language = sys.argv[1]
    title_slug = sys.argv[2]
    save_problem(language, title_slug)
