# -*- coding:utf-8 -*-

import os
import sys
import datetime
import math
import numpy as np
import cv2
import time

import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.pylab as pylab
import matplotlib.cm as cm

from itertools import product
from matplotlib import offsetbox
from sklearn import (manifold, datasets, decomposition, ensemble,
                     discriminant_analysis, random_projection)
from sklearn import datasets
from sklearn.datasets import fetch_mldata
from sklearn.utils import shuffle
from mpl_toolkits.mplot3d import Axes3D
Axes3D



class ManifoldLearningVis():
    def __init__(self, datapath='.'):
        # load iris 
        print ('Loading iris ..')
        self.iris = load_iris()         
        print ('Loading iris done..')       
         

    ## iris
    def generateData(self, data_type, data_example_cnt=0):
        if data_type == 'iris':
            iris = datasets.load_iris(n_class=10)
            return iris         
        else:
            print ('Wrong data_type.')
            return None   
     
    
    ## do manifold learning linear&nonlinear
    ## https://www.jianshu.com/p/2542e0a5bdf8
    """linear"""
    ## PCA:                    sklearn.decomposition.PCA
    ## LDA:                    sklearn.discriminant_analysis.LinearDiscriminantAnalysis
    ## Random Projection:    sklearn.random_projection.SparseRandomProjection
    """nonlinear"""
    ## LE:                    sklearn.manifold.SpectralEmbedding
    ## LLE:                    sklearn.manifold.LocallyLinearEmbedding
    ## ISOMAP:                sklearn.manifold.Isomap
    ## MDS:                    sklearn.manifold.MDS
    ## T-SNE:                sklearn.manifold.TSNE
    ## Random Forest Embedding

    def checkKey(self, str, dic):
        if not str in dic.keys():
            scode = 'Miss Key: ' % (str)
            print(scode)
            return [scode]
        else:
            pass
        
    def doManifoldLearning(self, data_type, method_type, param_dic):
        data = None
        if data_type == 'iris':
            data = self.iris.data
            label = self.iris.target         
        else:
            print ('Wrong data_type.')
            return None
            
        if data is None:
            return None
        
        self.checkKey('n_components', param_dic)
                
        if method_type == 'PCA':
            self.checkKey('whiten', param_dic)
            return [self.doPCA(data, n_components=param_dic['n_components'], whiten=param_dic['whiten']), label]
        elif method_type == 'LDA':
            X2 = data.copy()
            X2.flat[::data.shape[1] + 1] += 0.01  # Make X invertible
            return [self.doLDA(X2, label, n_components=param_dic['n_components']), label]
        elif method_type == 'RP':
            return [self.doRandomProj(data, n_components=param_dic['n_components']), label]
        elif method_type == 'ISOMAP':
            self.checkKey('n_neighbors', param_dic)
            return [self.doISOMAP(data, n_components=param_dic['n_components'], n_neighbors=param_dic['n_neighbors']), label]
        elif method_type == 'LE':
            return [self.doLE(data, n_components=param_dic['n_components']), label]
        elif method_type == 'LLE':
            self.checkKey('n_neighbors', param_dic)
            return [self.doLLE(data, n_components=param_dic['n_components'], n_neighbors=param_dic['n_neighbors']), label]
        elif method_type == 'MDS':
            self.checkKey('n_iter', param_dic)
            return [self.doMDS(data, n_components=param_dic['n_components'], n_iter=param_dic['n_iter']), label]
        elif method_type == 'TSNE':
            self.checkKey('n_iter', param_dic)
            return [self.doTSNE(data, n_components=param_dic['n_components'], n_iter=param_dic['n_iter']), label]
        elif method_type == 'RFE':
            self.checkKey('max_depth', param_dic)
            return [self.doRFE(data, n_components=param_dic['n_components'], max_depth=param_dic['max_depth']), label]
        else:
            print ('Wrong method_type.')
            return None
        
    def doPCA(self, data, n_components=2, whiten=False):
        pca = decomposition.PCA(n_components=n_components, whiten = whiten)
        X_transformed = pca.fit_transform(data)
        return X_transformed
    
    def doLDA(self, data, label, n_components=2):
        lda = discriminant_analysis.LinearDiscriminantAnalysis(n_components=n_components, solver='svd')
        X_transformed = lda.fit_transform(data, label)
        return X_transformed

    def doRandomProj(self, data, n_components=2):
        rp = random_projection.SparseRandomProjection(n_components=n_components)
        X_transformed = rp.fit_transform(data)
        return X_transformed
        
    def doISOMAP(self, data, n_components=2, n_neighbors=30):
        isomap = manifold.Isomap(n_neighbors=n_neighbors, n_components=n_components)
        X_transformed = isomap.fit_transform(data)
        return X_transformed
    
    def doLE(self, data, n_components=2):
        le = manifold.SpectralEmbedding(n_components=n_components, random_state=0,
                                      eigen_solver="arpack")
        X_transformed = le.fit_transform(data)
        return X_transformed
        
    def doLLE(self, data, n_components=2, n_neighbors=30):
        lle = manifold.LocallyLinearEmbedding(n_neighbors=n_neighbors, n_components=n_components,
                                      method='standard')
        X_transformed = lle.fit_transform(data)
        return X_transformed
        
    def doMDS(self, data, n_components=2, n_iter=50):
        mds = manifold.MDS(n_components=n_components, n_init=1, max_iter=n_iter)
        X_transformed = mds.fit_transform(data)
        return X_transformed
    
    def doTSNE(self, data, n_components=2, n_iter=300):
        tsne = manifold.TSNE(n_components = n_components, perplexity=40, n_iter = n_iter, init='pca', verbose=2)
        #tsne = manifold.TSNE(n_components=n_components, n_iter = n_iter, init='pca', random_state=0)
        X_transformed = tsne.fit_transform(data)
        return X_transformed
    
    def doRFE(self, data, n_components=2, max_depth=5):
        rfe = ensemble.RandomTreesEmbedding(n_estimators=200, random_state=0,
                                       max_depth=max_depth)
        X_transformed = rfe.fit_transform(data)
        pca = decomposition.TruncatedSVD(n_components=n_components)
        X_reduced = pca.fit_transform(X_transformed)
        return X_reduced
        
    def plot_embedding2D(self, X, y, title, outVisPath):
        fig = plt.figure(figsize=(10, 6))
        ax = plt.axes()
        #fig.set_size_inches(50, 50)
        #plt.prism()
        plt.jet()

        p=ax.scatter(X[:, 0], X[:, 1], c=y)
        fig.colorbar(p)
        #ax.colorbar()
        ax.set_xlabel('x-axis')
        ax.set_ylabel('y-axis')

        #plt.tight_layout()
        #plt.suptitle(title, fontsize=20)
        count = 0
        print(X.shape)
        for label, x, y in zip(y, X[:, 0], X[:, 1]):
        ##Lets annotate every 1 out of 200 samples, otherwise graph will be cluttered with anotations
            if count % 30 == 0:
                #plt.annotate(str(int(label)),xy=(x,y), color='black', weight='normal',size=10,bbox=dict(boxstyle="round4,pad=.5", fc="0.8"))
                ax.text(x, y, '%s' % str(int(label)), size=15, color='black', weight='normal') 
            count = count + 1

        plt.show()
        plt.savefig(outVisPath, bbox_inches='tight')
        plt.clf()

    def plot_iris_embedding2D(self, X, y, title, outVisPath):
        x_min, x_max = np.min(X, 0), np.max(X, 0)
        X = (X - x_min) / (x_max - x_min)

        plt.figure()
        ax = plt.subplot(111)
        for i in range(X.shape[0]):
            plt.text(X[i, 0], X[i, 1], str(self.iris.target[i]),
                     color=plt.cm.Set1(y[i] / 10.),
                     fontdict={'weight': 'bold', 'size': 9})

        if hasattr(offsetbox, 'AnnotationBbox'):
            # only print thumbnails with matplotlib > 1.0
            shown_images = np.array([[1., 1.]])  # just something big
            for i in range(self.iris.data.shape[0]):
                dist = np.sum((X[i] - shown_images) ** 2, 1)
                if np.min(dist) < 4e-3:
                    # don't show points that are too close
                    continue
                shown_images = np.r_[shown_images, [X[i]]]
                imagebox = offsetbox.AnnotationBbox(
                    offsetbox.OffsetImage(self.iris.images[i], cmap=plt.cm.gray_r),
                    X[i])
                ax.add_artist(imagebox)
        plt.xticks([]), plt.yticks([])
        #if title is not None:
        #    plt.title(title)

        plt.show()
        plt.savefig(outVisPath, bbox_inches='tight')
        plt.clf()
        
    def plot_embedding3D(self, X, y, title, outVisPath):
        fig = plt.figure(figsize=(10, 6))
        ax = plt.axes(projection='3d')
        #fig.set_size_inches(50, 50)
        #plt.prism()
        plt.jet()

        p=ax.scatter3D(X[:, 0], X[:, 1], X[:, 2], c=y)
        fig.colorbar(p)
        #ax.colorbar()
        ax.set_xlabel('x-axis')
        ax.set_ylabel('y-axis')
        ax.set_zlabel('z-axis')

        #plt.tight_layout()
        #plt.suptitle(title, fontsize=20)
        count = 0
        print(X.shape)
        for label, x, y, z in zip(y, X[:, 0], X[:, 1], X[:, 2]):
        ##Lets annotate every 1 out of 200 samples, otherwise graph will be cluttered with anotations
            if count % 30 == 0:
                #plt.annotate(str(int(label)),xy=(x,y), color='black', weight='normal',size=10,bbox=dict(boxstyle="round4,pad=.5", fc="0.8"))
                ax.text(x, y, z, '%s' % str(int(label)), size=15, color='black', weight='normal') 
            count = count + 1

        plt.show()
        plt.savefig(outVisPath, bbox_inches='tight')
        plt.clf()
        
if __name__=="__main__":
    mlM = ManifoldLearningVis()    
    paramDic={}
    paramDic['whiten'] = False
    paramDic['max_depth'] = 5
    paramDic['n_iter'] = 500  #need > 500
    paramDic['n_components'] = 2
    paramDic['n_neighbors'] = 10
    # 1. PCA        linear        Principal Components Analysis
    # 2. LDA        linear        Linear Discriminant Analysis
    # 3. RP            linear        Random Projection
    # 4. LE            non-linear    Spectral Embedding
    # 5. LLE        non-linear    Locally Linear Embedding
    # 6. ISOMAP        non-linear    ISOMAP
    # 7. MDS        non-linear    Multi-dimensional Scaling
    # 8. TSNE        non-linear    t-distributed Stochastic Neighbor Embedding
    # 9. RFE        non-linear    Random Forest Embedding
    
    X,y=mlM.doManifoldLearning('iris', 'PCA', paramDic)
    mlM.plot_embedding2D(X, y, 'manifold-learning', 'vis_manifold.png')

