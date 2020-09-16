from __future__ import print_function, division
import os
import torch
import pandas as pd
from skimage import io, transform
import numpy as np
import matplotlib.pyplot as plt
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms, utils

import warnings
warnings.filterwarnings('ignore')


if __name__ == "__main__":
    # read all image feature
    landmarks_frame = pd.read_csv('data/face/face_landmarks.csv')
    imgage_name = landmarks_frame.iloc[n, 0]

    print('image name: {}'.format(imgage_name))
