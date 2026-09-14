---
description: 알고리즘 문제 URL을 받아 올바른 디렉토리에 Kotlin 파일을 생성합니다. 코드는 사용자가 직접 작성합니다.
---

사용자가 URL을 제공하면 다음을 수행합니다:

## 1. 플랫폼 감지 및 파일 경로 결정

**LeetCode** (`leetcode.com/problems/<slug>/`):
- 파일: `leetcode/<slug>.kt`
- 예: `https://leetcode.com/problems/gcd-of-strings/` → `leetcode/gcd-of-strings.kt`

**프로그래머스** (`programmers.co.kr`):
- WebFetch로 페이지 접근해 문제 제목 확인
- 파일: `programmers/<한글문제명>.kt` (공백 제거)
- 예: `programmers/두큰수의합.kt`

**백준** (`acmicpc.net/problem/<번호>`):
- 알고리즘 유형을 사용자에게 묻거나 문제 태그에서 추론
- 파일: `backjoon/<유형>/<번호>/Main.kt`

## 2. 파일 생성

사용자가 코드를 별도로 제공한 경우 → 그 코드로 파일 생성
제공하지 않은 경우 → 빈 파일 생성 (내용 없음)

이미 파일이 존재하면 사용자에게 덮어쓸지 확인합니다.

## 3. 완료 안내

생성된 파일 경로를 알려줍니다.
