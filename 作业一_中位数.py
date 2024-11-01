# nums1=list(input().split())
# nums2=list(input().split())
# l1=len(nums1)
# l2=len(nums2)
#--------------------------
# m=input()
# m=int(m)
# n=input()
# n=int(n)
# nums1=[]
# nums2=[]
# for i in range(0,m):
#     nums1[i]=input()
# for j in range(0,n):
#     nums2[j]=input()
# for i in range(0,m):
#     nums1[i]=int(nums1[i])
# for j in range(0,n):
#     nums2[j]=int(nums2[j])
# if m%2==0:
#     m_=int(m/2)
#     print((nums1[m_]+nums1[m_+1])/2)
# else:
#     m_=int((m-1)/2)
#     print(nums1[m_])
# if n%2==0:
#     n_=int(n/2)
#     print((nums1[n_]+nums1[n_+1])/2)
# else:
#     n_=int((n-1)/2)
#     print(nums1[n_])
#-----------------------------------
# m=input()
# m=int(m)
# n=input()
# n=int(n)
#
# nums=[input() for i in range(m)]
#--------------------------------------------------------------------------------------------
#一开始题目看错了，以为是分别返回各自的
#但是这个错的也运行不了，输入有问题，数组都输不进
#下面是改了的，==没有输入部分==，如果部长能帮忙看看上面的问题在哪、该怎么改的话将不胜感激
#============================================================================================================
nums1=[2,4,6,8,10]
nums2=[1,3,5,7,9]
m=len(nums1)
n=len(nums2)
g=m+n
gnum=nums1+nums2
#冒泡排序
for i in range(g):
    for j in range(g-i-1):
        if(gnum[j]>gnum[j+1]):
            gnum[j],gnum[j+1]=gnum[j+1],gnum[j]
if(g%2==0):
    k=int(g/2)
    print((gnum[k]+gnum[k-1])/2)
else:
    k=int((g-1)/2)
    print(gnum[k])
#这个k也蛮生硬的，但是出现arr[k/2]就会报错我也不知道有什么好办法