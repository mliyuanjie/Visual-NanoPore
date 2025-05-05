import sys
import rlcompleter
import gc
from types import ModuleType
import numpy 
import pandas 
import matplotlib.pyplot as plt 

plt.switch_backend('TkAgg')

gc.collect()
_completer = rlcompleter.Completer()


class _CatchOutErr:
	def __init__(self):
		self.value = ''
	def write(self, txt):
		self.value += txt
	def flush(self):
		self.value = ''
_catchOutErr = _CatchOutErr()
sys.stdout = _catchOutErr
sys.stderr = _catchOutErr

def _completion(s):
	res = ''+s
	for i in range(50):
		items = _completer.complete(s, i)
		if items is None:
			break
		else:
			res=res+','+items
	return res

def _loadDAT(fn = None):
	return numpy.memmap(fn, dtype = 'float32', mode = 'r', )

def _loadCSV(fn=None):
	df = pandas.read_csv(fn[:-3]+'csv', index_col = None, usecols=['start', 'end'], dtype = numpy.int32)
	p = df.to_dict(orient = 'list')
	return p

def _getEvent(data, event, i):
	return data[event['start'][i]:event['end'][i]]

def _clearWorkSpace():
	_all = [k for k,v in globals().items() if type(v) is ModuleType and not k.startswith('__')]  
	for i in _all:
		if i in ['sys', 'gc', 'rlcompleter', 'ModuleType', 'numpy', 'pandas', 'plt']:
			continue
		del sys.modules[i]
		del globals()[i]
	gc.collect()

def _getModuleList():
	return [k for k,v in globals().items() if type(v) is ModuleType and not k.startswith('__')]  
data = None
event= None