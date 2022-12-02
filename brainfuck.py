import sys

def run(code):
    arr = [0]
    ptr = 0
    loops = 0
    i = 0
    while i<len(code):
        if code[i]=="+":
            arr[ptr]+=1
            if arr[ptr]>255:
                arr[ptr]=0
        elif code[i]=="-":
            arr[ptr]-=1
            if arr[ptr]<0:
                arr[ptr]=255

        elif code[i]==">":
            ptr+=1
            if len(arr)<=ptr:
                arr.append(0)
        elif code[i]=="<":
            if ptr>0:
                ptr-=1

        elif code[i]==".":
            print(chr(arr[ptr]),end="")
        elif code[i]==",":
            arr[ptr]=ord(input())

        elif code[i]=="[":
            if arr[ptr]==0:
                loops=1
                while loops>0:
                    i+=1
                    if code[i]=="[":
                        loops+=1
                    elif code[i]=="]":
                        loops-=1
        elif code[i]=="]":
            loops=1
            while loops>0:
                i-=1
                if code[i]=="[":
                    loops-=1
                elif code[i]=="]":
                    loops+=1
            i-=1

        i+=1

if __name__=="__main__":
    with open(str(sys.argv[1])) as f:
        code = f.read()
        run(code)
