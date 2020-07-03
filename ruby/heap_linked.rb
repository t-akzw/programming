class Node
  attr_accessor :val, :next

  def initialize(val)
    @val = val
    @next = nil
  end
end

class LinkedList
  attr_reader :head

  def initialize(val)
    @head = Node.new(val)
  end

  def add_tail(val)
    node = search_tail(@head)
    node.next = Node.new(val)
  end

private
  def search_tail(node)
    return node if (!node.next or node.next == @head)
    search_tail(node.next)
  end
end

def sort_list(head)
  merge_sort_rec(head)
end

def merge_sort_rec(list)
  return list if list.next.nil?
  middle_node = search_middle_index(list)
  merge(merge_sort_rec(list), merge_sort_rec(middle_node))
end

# 重要： 真ん中のindexを探すために、x2で移動するbと、
#        x1で移動するaを用意して、bがnilに到達した時のaが真ん中
def search_middle_index(list)
  a = list
  b = list
  until b.next.nil? || b.next.next.nil?
    a = a.next
    b = b.next.next
  end
  tmp = a.next
  a.next = nil
  tmp
end

def merge(a, b)
  until a.nil? || b.nil?
    if a.val <= b.val
      
    end
  end
end

l = LinkedList.new(4)
l.add_tail(2)
l.add_tail(1)
l.add_tail(3)
l.add_tail(5)
l.add_tail(6)
l.add_tail(9)
sort_list(l.head)


