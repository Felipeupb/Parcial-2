using System;

namespace p1
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] array;

			array = crear_array(100);
			llenar_array(array);
			imprimir_array(array);
			Console.ReadKey();

		}	
		static int[] crear_array(int size)
		{
			int[] array_temp = new int[size];

			return array_temp;
		}
		static void llenar_array(int[] array)
		{
			for(int i = 0; i < 100; i++)
			{
				array[i] = i;
			}
		}
		static void imprimir_array(int[] array)
		{
			for (int i = 0; i < array.Length; i++)
			{
				Console.WriteLine("Array["+i+"] = "+ array[i]);
			}
		}

	}
}