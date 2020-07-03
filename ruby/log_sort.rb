class Array
  def merge_sort
    merge_sort_rec(self.dup)
  end

private
  def merge_sort_rec(array)
    return array if array.size <= 1
    middle_index = array.size/2
    a = merge_sort_rec(array[0...middle_index])
    b = merge_sort_rec(array[middle_index..-1])
    merge(a, b)
  end

  def merge(a, b)
    res = []
    loop_num = [a, b].map(&:size).inject(&:+)
    loop_num.times do   
      res <<
        case
        when a.empty? then b.shift
        when b.empty? then a.shift
        when a.first < b.first then a.shift
        else b.shift
        end
    end
    res
  end
end
