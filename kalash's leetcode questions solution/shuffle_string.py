class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        return ''.join(map(lambda x: x[1], sorted(zip(indices, s))))
