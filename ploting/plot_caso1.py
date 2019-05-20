import numpy as np
import matplotlib.pyplot as plt

# data to plot
n_groups = 3

lost_packets = (770, 108, 0)
recive_packets = (998, 998, 996)
in_queue = (211, 201, 135)
generated = (1979, 1307, 1129)

# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.1
opacity = 0.7


rects4 = plt.bar(index, generated, bar_width,
alpha=opacity,
color='b',
label='Paquetes generados')

rects1 = plt.bar(index + bar_width*3, lost_packets, bar_width,
alpha=opacity,
color='r',
label='Paquetes perdidos')


rects3 = plt.bar(index + bar_width*2, in_queue, bar_width,
alpha=opacity,
color='y',
label='Paquetes en cola')


rects2 = plt.bar(index + bar_width, recive_packets, bar_width,
alpha=opacity,
color='g',
label='Paquetes recibidos')

# plt.xlabel()
plt.ylabel('Cantidad de paquetes')
plt.title('Paquetes generados, recibidos en Sink, en cola y los perdidos')
plt.xticks(index + bar_width, ('0.1', '0.15', '0.175'))
plt.legend()

plt.tight_layout()
plt.show()
