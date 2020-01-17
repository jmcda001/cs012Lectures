from random import randrange

# Parameter
MAX = 100000
CSV = False

l = [str(i) for i in range(MAX)]
for _ in range(MAX):
    i = randrange(MAX)
    j = randrange(MAX)
    l[i],l[j] = l[j],l[i]

fn = 'large_input'
ext = '.csv' if CSV else '.txt'

with open(fn+ext,'w') as f:
    joiner = ',' if CSV else ' '
    f.write(joiner.join(l))
