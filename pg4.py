n=input("Limit:")
print "Elements"
l=[]

for i in range(n):
   x=input()
   l.append(x)
for i in reversed(range(0,n)):
   a=l[i]
   for j in reversed(range(i+1,n-1)):
      if l[j]==a:
         del l[j]
       
      
print l
