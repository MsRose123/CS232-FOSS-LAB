m=input("r=")
n=input("c=")
l=[]
print "Enter elements"
for i in range(m):
   a=[]
   for j in range(n):
       x=input()
       a.append(x)
   l.append(a)
small=l[0][0]
p=0
q=0
for i in range(m):
   for j in range(n):
       if l[i][j]<small:
           small=l[i][j]
           p=i
           q=j
print "Smallest=",small
print "Row",p+1
print "Column",q+1
