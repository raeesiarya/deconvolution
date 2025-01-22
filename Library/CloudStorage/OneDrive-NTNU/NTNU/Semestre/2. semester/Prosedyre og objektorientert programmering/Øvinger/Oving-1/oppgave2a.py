#%%
def isFibonaccinumber(n):
    a = 0
    b = 1
    
    while b < n:
        temp = b
        b += a
        a = temp
        
    return b == n

isFibonaccinumber(5)
# %%
