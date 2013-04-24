bool uppertolower(char *s1, char *s2, int i)
{
  if (((s1[i] + 32) != s2[i]) && (s1[i] != s2[i]))
          {
            return false;
          }
  return true;
}

bool lowertoupper(char *s1, char *s2, int i)
{
  if (((s1[i] - 32) != s2[i]) && (s1[i] != s2[i]))
    {
      return false;
    }
  return true;
}

bool mystrcmp(char *s1, char *s2)
{
  int i = 0;
  while (s1[i] != 0)
    {
      switch((int)s1[i])
	{
	case 65:
	case 66:
	case 67:
	case 68:
	case 69:
	case 70:
	case 71:
	case 72:
	case 73:
	case 74:
	case 75:
	case 76:
	case 77:
	case 78:
	case 79:
	case 80:
	case 81:
	case 82:
	case 83:
	case 84:
	case 85:
	case 86:
	case 87:
	case 88:
	case 89:
	case 90:
	  // uppercase letter
	  if(!uppertolower(s1, s2, i))
	    {
	      return false;
	    }
	  break;
	case 97:
	case 98:
	case 99:
	case 100:
	case 101:
	case 102:
	case 103:
	case 104:
	case 105:
	case 106:
	case 107:
	case 108:
	case 109:
	case 110:
	case 111:
	case 112:
	case 113:
	case 114:
	case 115:
	case 116:
	case 117:
	case 118:
	case 119:
	case 120:
	case 121:
	case 122:
	  if (!lowertoupper(s1, s2, i))
	    {
	      return false;
	    }
	  break;
	default:
	  if (s1[i] != s2[i])
	    {
	      return false;
	    }
	}
      i++;
    }

  if (s2[i] == 0)
    {
      return true;
    }

  return false;

}	  

//clamps input to a range of 0 to 255
int clamp(int input)
{
  if(input < 0)
    {
      return 0;
    }
  if(input > 255)
    {
      return 255;
    }
  return input;
}

int clampval(int input, int min, int max)
{
  if(input < min)
    {
      return min;
    }
  if(input > max)
    {
      return max;
    }
  return input;
}

//clamps input to a range of 0 to 1
double clampa(double alpha)
{
  if (alpha < 0)
    {
      return 0.0;
    }
  if (alpha > 1)
    {
      return 1.0;
    }
  return alpha;
}

bool isOdd(int x)
{
  if ((x + 1)/2 > x/2)
    {
      return true;
    }
  return false;
}
