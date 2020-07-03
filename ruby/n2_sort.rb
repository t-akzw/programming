class Array
  def swap!(a, b)
    self[a], self[b] = self[b], self[a]
    self
  end

  def insertion_sort
    setloop
    @tmp = []
    self.each do |i|
      insertion_index = binary_search(i)
      @tmp.insert(insertion_index, i)
    end
    @tmp
  end

private
  def setloop
    @loop = self.size - 1
  end

  def linear_search(val)
    return 0 if @tmp.empty?
    @tmp.each_with_index do |v, i|
      return i if v > val
    end
    @tmp.size
  end

  def binary_search(val)
    return 0 if @tmp.empty?
    lower = 0
    upper = @tmp.size - 1
    while lower <= upper do
      middle = (upper + lower)/2
      if @tmp[middle] == val
        return middle
      elsif @tmp[middle] < val
        lower = middle + 1
      else
        upper = middle - 1
      end
    end
    lower
  end
end
