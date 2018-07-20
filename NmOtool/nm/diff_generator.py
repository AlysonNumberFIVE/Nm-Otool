




import sys
import os

def diff_generator(filename):

    print(' FILENAME >>> ', filename)
    arg = './ft_nm ' + filename + ' | sort > mine.txt'
    os.system(arg)
    arg = 'nm ' + filename + ' | sort > theirs.txt'
    os.system(arg)
    os.system("diff mine.txt theirs.txt")

def diff_loop():

    pathway = sys.argv[1]
    for root, dirs, files in os.walk(pathway):
        path = root.split(os.sep)
        print((len(path) - 1) * '---', os.path.basename(root))
        for f in files:
            st = pathway + '/' + f 
            diff_generator(st)

diff_loop()
