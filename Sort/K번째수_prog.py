# 정렬 level_1

array = [1, 5, 2, 6, 3, 7, 4]
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]


def solution(array, commands):
    answer = []

    for cmd in commands:
        sp_array = array[(cmd[0] - 1) : cmd[1]]
        sp_array.sort()
        answer.append(sp_array[cmd[2] - 1])

    return answer


print(solution(array, commands))
