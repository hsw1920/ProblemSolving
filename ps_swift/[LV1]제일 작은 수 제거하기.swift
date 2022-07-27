func solution(_ arr:[Int]) -> [Int] {
    var newArr:[Int] = []
    var minNum = arr[0]
    var idx = 0
    for i in 0..<arr.count {
        newArr.append(arr[i])
        if minNum>arr[i] {
            idx = i
            minNum = arr[i]
        }
    }
    newArr.remove(at: idx)
    if newArr.count == 0 {
        newArr.append(-1)
    }
    
    return newArr
}