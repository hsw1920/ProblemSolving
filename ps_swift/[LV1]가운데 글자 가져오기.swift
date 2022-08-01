func solution(_ s:String) -> String {
    var arr = Array(s)
    var n = arr.count 
    var str = ""
    var k = n/2
    if n%2==0 {
        // 짝수
        str.append(arr[k-1])
        str.append(arr[k])
    }
    else {
        str.append(arr[k])
    }
    return String(str)
}