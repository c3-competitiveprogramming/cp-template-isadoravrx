def pegar3ultimos(n):
    temp = str(n)
    result = ""
    
    cont = 0
    for i in range(len(temp)-1,-1,-1):
        if cont >= 3:
            break
        result += temp[i]
        cont+=1
    
    result2 = ""    
    for i in range(len(result) - 1, -1, -1):
        result2 += result[i]
        
    return int(result2)


t = int(input())

while(t > 0):
    t-=1
    n, k = map(int, input().split())

    ans1 = 1
    ans2 = 1
    tresultimos = pegar3ultimos(n)
    for i in range(k):    
        ans1 = (ans1 * n) % 10000000000000000000000000000000000000000000000000000000
        ans2 = (ans2 * tresultimos)

    ans2 = pegar3ultimos(ans2)
    
    ans1 = str(ans1)
    ans2 = str(ans2)
    for i in range(3):
        print(ans1[i], end="")

    print("...", end="")
    
    for i in range(3):
        print(ans2[i], end="")

    print()

