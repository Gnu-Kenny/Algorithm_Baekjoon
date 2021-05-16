# 정렬 level_2
# sort key=lamda
from itertools import permutations

numbers = [3, 30, 34, 5, 9]
# [3, 30, 34, 5, 9] return "9534330"


def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(
        key=lambda x: x * 3, reverse=True
    )  # lamda:x*3 => 인수의 값이 1000이하 이므로 3번 반복

    return str(int("".join(numbers)))  # 모든 값이 0일때 ('000'처리를 위해) int로 변환한 뒤, 다시 str


solution(numbers)

# 시간 초과 코드
# from itertools import permutations

# def int_to_str(numbers):
#     strNumbers = []
#     for number in numbers:
#         strNumbers.append(str(number))

#     return strNumbers

# def solution(numbers):
#     answer = ''
#     strNumbers = int_to_str(numbers)
#     new_numbers = list(permutations(strNumbers))
#     apNumbers = []
#     for new_number in new_numbers:
#         apNumbers.append("".join(new_number))
#     answer += sorted(apNumbers, reverse=True)[0]
#     return answer
