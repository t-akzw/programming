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
    @queue = []
  end

  def bfs
    traverse(@head)
  end

private
  def traverse(node)
    return @list if node.nil?

    @list << node.val
    @queue << node.left if !!node.left
    @queue << node.right if !!node.right
    node = @queue.shift 
    traverse(node)
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

bt.bfs
