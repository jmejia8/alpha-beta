from math import sqrt

INF = float("inf")

class AlphaBeta(object):
	"""
	Implementación del algoritmo:
		poda alpha-beta
	"""
	def __init__(self, tree, children, deep):
		super(AlphaBeta, self).__init__()
		self.tree = tree
		self.maxDeep = deep
		self.children = children

		self.node = 0

	def run(self, α, β, maxx, node = 0, deep = 0):

		print(α, β, node, deep, end = "")

		if deep == self.maxDeep:
			value = self.tree[self.node]
			self.node += 1
			print("\t>>>>>>>>>>>>>  ", value)
			return value

		print()

			
		deep += 1
		
		
		if maxx:
			v = -INF
		
			for child in range(self.children):
				v = max([v, self.run(α, β, not maxx, child, deep)])
				α = max([α, v])

				if β <= α : break

			return v

		v = INF
		
		for child in range(self.children):
			v = min([v, self.run(α, β, maxx, child, deep)])
			β = min([β, v])

			if β <= α : break

		return v






def main():
	nodes = [8, 7, 3, 9, 9, 8, 2, 4, 1, 8, 8, 9, 9, 9, 3, 4]

	alphaBeta = AlphaBeta(nodes, 2, 4)
	print (alphaBeta.run(-INF, INF, True))



if __name__ == '__main__':
	main()