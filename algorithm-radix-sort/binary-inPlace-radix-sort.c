/*
@startuml
start
note right
    **Binary In-place Radix Sort Algorithm**
    RadixSort(data, digit, startIdx, endIdx) 
    // first, call RadixSort(data, MSB, 0, lengthOfData-1)
end note

partition Do-Radix-Sort {
    :idxOf0 = startIdx
    idxOf1 = endIdx;
    repeat
        while (digit of data[idxOf0++] == 0) is (yes)
        endwhile (no)
        while (digit of data[idxOf1--] == 1) is (yes)
        endwhile (no)
        :swap(data[idxOf0], data[idxOf1]);
    repeat while (idxOf0-1 == idxOf1) is (no)
    -> yes;
    :startIdxOf0 = startIdx
    endIdxOf0 = idxOf0
    startIdxOf1 = idxOf1
    endIdxOf1 = endIdx;
}

if (digit == 1) then (yes)
else (no)
  :call RadixSort(data, digit-1, startIdxOf0, endIdxOf0);
  :call RadixSort(data, digit-1, startIdxOf1, endIdxOf1);
endif

end
note right
    return
end note
@enduml
*/