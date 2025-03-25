class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        li=[]
        for pos,sp in zip(position,speed):
            li.append([pos,sp])
        li.sort(key=lambda x:x[0],reverse=True)
        st=[]
        cnt=0
        # print(li)
        for pos,sp in li:
            cur= (target-pos)/sp 
            print(pos,sp,cur)
            # print(cur)
            while len(st)>0 and cur>st[-1]:
                st.pop()
            if len(st)<1:
                cnt+=1
            st.append(cur)
        return cnt
