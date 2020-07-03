class Node
  attr_accessor :val, :next, :prev

  def initialize(val)
    @val = val
    @next = nil
    @prev = nil
  end
end

class LinkedList
  attr_reader :head

  def initialize(val)
    @head = Node.new(val)
  end

  def add_tail(val, circulation=false)
    node = search_tail(@head)
    node.next = Node.new(val)
    node.next.prev = node

    if circulation
      node.next.next = @head
      @head.prev = node.next
    end
  end

  def del_tail(circulation=false)
    new_tail = search_tail(@head).prev
    new_tail.next = nil if !!new_tail

    if circulation
      new_tail.next = @head
      @head.prev = new_tail
    end
  end

  def clear_list
    @head.next = nil
  end

private
  # 引数としてNodeを渡してそのNodeの次にNodeを連結させる
  # Nodeを追加することだけが責務
  def append_list(obj, val)
    obj.next = Node.new(val)
  end

  def search_tail(node)
    return node if (!node.next or node.next == @head)
    search_tail(node.next)
  end
end

l = LinkedList.new(1)
l.add_tail(2)
l.add_tail(3, true)
l.del_tail(true)
