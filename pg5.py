n=input("Limit:")
print "Elements"
l=[]

for i in range(n):
   x=input()
   l.append(x)
for i in reversed(range(0,n)):
   if l.count(l[i])>1:
       del l[i]
print l
