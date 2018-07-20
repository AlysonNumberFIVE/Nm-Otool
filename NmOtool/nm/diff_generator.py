

import sys
import os

def diff_generator():

    filename = sys.argv[1]
    arg = './ft_nm ' + filename + ' | sort > mine.txt'
    os.system(arg)
    arg = 'nm ' + filename + ' | sort > theirs.txt'
    os.system(arg)

diff_generator()
