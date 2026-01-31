def solve(N):
    if N == 1:
        ans=["A -> C"]
        return ans
    else:
        mem=solve(N-1)
        ans=[]
        for move in mem:
            if move=="A -> C":
                ans.append("A -> B")
            elif move=="A -> B":
                ans.append("A -> C")
            elif move=="B -> C":
                ans.append("C -> B")
            elif move=="C -> B":
                ans.append("B -> C")
            elif move=="B -> A":
                ans.append("C -> A")
            else:
                ans.append("B -> A")
        ans.append("A -> C")
        for move in mem[::-1]:
            if move=="A -> C":
                ans.append("B -> C")
            elif move=="A -> B":
                ans.append("A -> C")
            elif move=="B -> C":
                ans.append("B -> A")
            elif move=="B -> A":
                ans.append("C -> A")
            elif move=="C -> B":
                ans.append("A -> B")
            else:
                ans.append("C -> B")
        return ans
n=int(input())
print(*solve(n),sep='\n')


