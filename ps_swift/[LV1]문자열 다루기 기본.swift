func solution(_ s:String) -> Bool {
    var arr = Array(s)
    var num = Array("0123456789")
    if arr.count == 4 || arr.count == 6 {
        for i in 0..<arr.count {
            if num.contains(arr[i]) {
                continue
            }
            else {
                return false
            }
        }
        return true
    }
    
    return false
}