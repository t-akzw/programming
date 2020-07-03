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
    @head.add_left(0)
    @head.left.add_right(3)
    @head.add_right(0)
  end

  def distribute_coins
    @result = 0
    dfs(@head)
    @result
  end

  def dfs(node)
    return 0 unless node
    left,right = dfs(node.left), dfs(node.right)
    @result += (left.abs + right.abs)
    p "node.val: #{node.val}, #{left} #{right}"
    return node.val + left + right - 1
  end
end
