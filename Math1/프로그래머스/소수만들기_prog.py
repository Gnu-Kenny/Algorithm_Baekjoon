# 소수만들기_프로그래머스[수학1]
# 에라토스테네스의 체 / 조합 / list comprehension / sum(list or tuple, start = )

from itertools import combinations
import math

# nums = [1,2,3,4]
nums = [1, 2, 7, 6, 4]


def is_prime_number(n):
    # 2부터 n까지의 모든 수에 대하여 소수 판별
    array = [True for i in range(n + 1)]  # 처음엔 모든 수가 소수(True)인 것으로 초기화(0과 1은 제외)

    # 에라토스테네스의 체
    for i in range(2, int(math.sqrt(n)) + 1):  # 2부터 n의 제곱근까지의 모든 수를 확인하며
        if array[i] == True:  # i가 소수인 경우(남은 수인 경우)
            # i를 제외한 i의 모든 배수를 지우기
            j = 2
            while i * j <= n:
                array[i * j] = False
                j += 1

    return array[n]


def solution(nums):
    answer = 0
    threeNums = list(combinations(nums, 3))  # 각 요소들을 튜플로 반환 이를 list로 묶음
    for i in threeNums:  # i는 threeNums 내 튜플 요소
        if is_prime_number(sum(i, start=0)):
            answer += 1

    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    # print('Hello Python')

    return answer


print(solution(nums))
