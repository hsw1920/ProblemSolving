import Foundation

func solution(_ s:String) -> Bool
{
    var t = 0;
    var p = 0;
    var arr = Array(s)
    for i in 0..<arr.count {
        if arr[i] == "p" || arr[i] == "P" {
            p+=1
        }
        else if arr[i] == "y" || arr[i] == "Y" {
            t+=1
        }
    }
    if p == t {
        return true
    }
    return false
}