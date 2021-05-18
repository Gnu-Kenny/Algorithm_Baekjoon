# 정렬 level_2
# enumerate -> 배열의 index와 value 반환

citations = [8, 0, 0, 0, 0]

# n편 중, h번 이상 인용된 논문이 h편 이상
def solution(citations):
    citations = sorted(citations, reverse=True)

    for index, value in enumerate(citations):  
        if index >= value:
            return index

    return len(citations)


print(solution(citations))
