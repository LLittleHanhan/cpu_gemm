import os
import matplotlib.pyplot as plt



path = './data/'
files = os.listdir(path)

plt.xlabel('N')
plt.ylabel('Gflops')
for file in files:
    print(path+file)
    x = []
    y = []
    with open(path+file,'r') as f:
        i = 0
        for line in f.readlines():
            if i==0:
                label = line
            else:
                x.append(int(line.strip().split(' ')[0]))
                y.append(float(line.strip().split(' ')[1]))
            i=i+1
        plt.plot(x,y,'o-',label=label)
plt.legend()
plt.show()
        
