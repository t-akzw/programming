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

class BinaryTree
  attr_reader :head, :list

  def initialize(val)
    @head = Node.new(val)
    @list = []
  end

  def pre
    @list = []
    traverse(@head, :pre)
    @list
  end

  def in
    @list = []
    traverse(@head, :in)
    @list
  end

  def post
    @list = []
    traverse(@head, :post)
    @list
  end

private
  def traverse(node, type=:pre)
    @list << node.val             if type == :pre
    traverse(node.left, type)     if !!node.left
    @list << node.val             if type == :in
    traverse(node.right, type)    if !!node.right
    @list << node.val             if type == :post
  end
end

bt = BinaryTree.new(7)
bt.head.add_left(3)
bt.head.left.add_left(1)
bt.head.left.add_right(4)
bt.head.left.right.add_right(6)
bt.head.left.right.right.add_left(5)
bt.head.add_right(10)
bt.head.right.add_left(8)

bt.pre
bt.in
bt.post

