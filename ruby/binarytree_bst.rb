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

class BinarySearchTree
  attr_reader :head, :list

  def initialize(val)
    @head = Node.new(val)
    @list = []
    @queue = []
  end

  def bst_add(val)
    @list = []
    node, type, _ = search(@head, val)
    node.add_left(val) if type == :left
    node.add_right(val) if type == :right
  end

  def bst_del(val)
    @list = []
    node, _, parent = search(@head, val)
    if node.val == val
      parent.left = node.left if parent.left == node
      parent.right = node.left if parent.right == node
    end
  end

  def bsearch(val)
    @list = []
    node, _, _ = search(@head, val)
    node.val == val
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

  def search(node, val, parent=nil)
    @list << node.val
    if val <= node.val
      return node, :left, parent if node.left.nil?
      search(node.left, val, node)
    else
      return node, :right, parent if node.right.nil?
      search(node.right, val, node)
    end
  end
end

bt = BinarySearchTree.new(12)
bt.head.add_left(9)
bt.head.left.add_left(3)
bt.head.left.add_right(11)
bt.head.add_right(25)
bt.head.right.add_left(18)
bt.head.right.add_right(27)

bt.bsearch(3)
bt.bsearch(4)
