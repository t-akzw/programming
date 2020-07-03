class Node
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
    @left = nil
    @right = nil
  end

  def add_left(val)
    self.left = Node.new(val)
  end

  def add_right(val)
    self.right = Node.new(val)
  end
end

class Bst
  def initialize(val)
    @head = Node.new(val)
    @list = []
  end

  def mktree
    @head.add_left(5)
    @head.left.add_left(3)
    @head.left.add_right(7)
    @head.add_right(15)
    @head.right.add_right(18)
  end

  def traverse(node)
    @list << node.val      if @l <= node.val and node.val <= @r
    traverse(node.left)    if !!node.left
    traverse(node.right)   if !!node.right
  end

  def range_sum_bst(l, r)
    @list = []
    @l = l
    @r = r
    traverse(@head)
    @list
  end
end
