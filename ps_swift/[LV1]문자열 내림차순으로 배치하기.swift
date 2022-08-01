import Foundation

func solution(_ s:String) -> String {
    var arr = Array(s)
    arr.sort(by:>)
    print(String(arr))
    return String(arr)
}