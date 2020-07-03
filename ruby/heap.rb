class Heap
  attr_reader :list

  def initialize
    @list = [nil]
  end

  def add(val)
    @list.push(val)
    up_heap(@list.size - 1)
    @list
  end

  def del(index=1)
    return if index < 1
    @list.swap!(index, -1)
    @list.pop
    down_root(index)
    @list
  end

private
  def up_heap(index)
    return if index <= 1
    parent_index = index/2
    if @list[parent_index] > @list[index]
      @list.swap!(parent_index, index)
      up_heap(parent_index)
    end
  end

  def down_root(index)
    child_index = small_child(index)
    return if child_index >= @list.size
    if @list[index] > @list[child_index]
      @list.swap!(index, child_index)
      down_root(child_index)
    end
  end

  def small_child(index)
    left = index*2
    right = index*2 + 1
    return left if @list[right].nil?
    return right if @list[left].nil?
    (@list[left] > @list[right])? right : left
  end
end

class Array
  def swap!(a, b)
    self[a], self[b] = self[b], self[a]
    self
  end
end

h = Heap.new
h.add(2)
h.add(7)
h.add(4)
h.add(9)
h.add(7)
h.add(4)
h.add(12)

h.add(3)
