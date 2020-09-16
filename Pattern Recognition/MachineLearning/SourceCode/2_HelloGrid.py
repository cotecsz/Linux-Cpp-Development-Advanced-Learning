import numpy as np
import sys
from six import StringIO, b

from gym import utils
from gym.envs.toy_text import discrete

# four actions
UP = 0
RIGHT = 1
DOWN = 2
LEFT = 3

# HelloGrid environment
MAPS = {'4x4':["SOOO", "OXOX", "OOOX", "XOOG"]}

class HelloGridEnv(discrete.DiscreteEnv):
    metadata = {'rendre.modes': ['human', 'ansi']}

    def __init__(self, desc=None, map_name='4x4'):
        """ Construct GridWorldEnv
        """
        # environment map Grid
        self.desc = np.asarray(MAPS[map_name], dtype='c')
        # get MAPS'shape
        self.shape = self.desc.shape

        # action numbers
        self.nA = 4
        # state numbers
        self.nS = np.prod(self.desc.shape)



if __name__ == '__main__':
    helloGird = HelloGridEnv()
    print('----------Init HelloGird Environment Info------------')
    print('\tshape of desc: {}'.format(helloGird.desc.shape))
    print('\tnumber of actions:{n_actions} \n\tnumber of states:{n_states}'\
        .format(n_actions=helloGird.nA, n_states=helloGird.nS))