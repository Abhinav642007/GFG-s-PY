class Solution:
    def utility(self, a, b, opr):
        # code here
        if(opr==1):
            n=a+b
            print(str(n))
        
        elif(opr==2):
            z=a-b
            print(str(z))
        
        elif(opr==3):
            x=a*b
            print(str(x))
        
        else:
            print("Invalid Input")