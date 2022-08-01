func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    // arr의 원소중 divisor로 나누어 떨어지는 값을 오름차순
    var array:[Int] = []
    for i in arr {
        if i%divisor == 0 {
            array.append(i)
        }
    }
    array.sort()
    if array.count == 0 {
        array.append(-1)
    }
    return array
}