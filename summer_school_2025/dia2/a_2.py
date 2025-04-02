M = 1000000007


def soma(a,b):
    return (a% M+b% M) % M

def sub(a,b):
    return (a-b + M) %M

def mult(a,b):
    return a% M * b% M % M
def exp1(x,k):
    k = k%(M-1)
    l1=""
    k1=k
    while(k1>0):
        l1= l1 + str(k1%2)
        k1=int(k1/2)
 
    potencia=1
    for i in range(len(l1)-1, -1, -1):
        if(l1[i]=='0'):
            potencia=mult(potencia,potencia) % M
        else:
            potencia=mult(mult(potencia,potencia) % M ,x) % M
 
    return potencia   

if __name__ == '__main__':

    s = input()
    s = s.split()

    a = int(s[0])
    opera = s[1]
    b = int(s[2])

    if(opera == "+"):
        print(soma(a,b))

    elif(opera == "-"):
        print(sub(a,b))

    if(opera == "*"):
        print(mult(a,b))

    if(opera == "^"):
        print(exp1(a,b))


