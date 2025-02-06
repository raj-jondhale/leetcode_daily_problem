
int majorityElement(int *nums, int numsSize)
{

    int mElement = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (count == 0)
        {
            mElement = nums[i];
            count = 1;
        }
        else if (mElement == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return mElement;
}