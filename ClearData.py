

input()
x = [];
y = [];

while True:
    try:
    
        Result = list(map(float ,input().split()))
        x.append(Result[0])
        y.append(Result[1]);
    except EOFError:
        print('x')
        print(x)
        print('y')
        print(y)
        break;

