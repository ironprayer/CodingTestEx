import math

def solution(progresses, speeds):
    answer = []
    count = 1
    progressLen = len(progresses)

    
    for index in range(0, progressLen) :
        curProcessDay = math.ceil((100 - progresses[index])/speeds[index])
        if index == 0 :
            checkDay = curProcessDay
        elif checkDay >= curProcessDay :
            count = count + 1
        else :
            answer.append(count)
            checkDay = curProcessDay
            count = 1
            
    if count > 0 and progressLen > 0 :
        answer.append(count)
        
    return answer