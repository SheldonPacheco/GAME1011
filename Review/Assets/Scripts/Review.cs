using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Review : MonoBehaviour
{
    public GameObject prefab;
    int a = 0;

    GameObject[] cubes = new GameObject[3];

    // Start is called before the first frame update
    void Start()
    {
        Greet();

        // Not very useful functions since C# has operators for +-*/
        Debug.Log(Add(1.0f, 2.0f));
        Debug.Log(Sub(1.0f, 2.0f));
        Debug.Log(Mul(1.0f, 2.0f));
        Debug.Log(Div(1.0f, 2.0f));

        // Try not to re-invent the wheel!
        Debug.Log(1.0f + 2.0f);
        Debug.Log(1.0f - 2.0f);
        Debug.Log(1.0f * 2.0f);
        Debug.Log(1.0f / 2.0f);

        // C# will choose the inner-most varialbe when faced with duplicate names
        {
            int a = 3;
            Debug.Log(a);
        }
        Debug.Log(a);

        // 3 different ways to increment a number
        //int integer = 5;
        //Debug.Log(integer);
        //integer = integer + 1;
        //integer += 1;
        //integer++;
        //Debug.Log(integer);

        // int & float are 32 bits each
        // double is 64 bits (hence the name "double")
        // Pay close attention to the precision used to calculate vs store!
        //float fraction = (float)(5.0 / 3.0);
        //float fraction = 5.0f / 3.0f;
        //float fraction = 5.5f;
        //Debug.Log(fraction);

        float x = -5.0f;
        float y = 1.5f;
        for (int i = 0; i < cubes.Length; i++)
        {
            GameObject cube = Instantiate(prefab);
            cubes[i] = cube;
            cube.transform.position = new Vector3(x, y, 0.0f);
            x += 5.0f;
        }
    }

    void Greet()
    {
        Debug.Log("Hello world!");
    }

    float Add(float a, float b)
    {
        return a + b;
    }

    float Sub(float a, float b)
    {
        return a - b;
    }

    float Mul(float a, float b)
    {
        return a * b;
    }

    float Div(float a, float b)
    {
        return a / b;
    }

    // Make a function that outputs a translation
    Vector3 Move(Vector3 direction, float speed)
    {
        return direction * speed;
    }

    // Update is called once per frame
    void Update()
    {
        float dt = Time.deltaTime;
        float tt = Time.realtimeSinceStartup;
        float cubeSpeed = 10.0f;
        float circleRadius = 5.0f;

        MoveCubesInDonutMotion(dt, tt, cubeSpeed, circleRadius);
    }

    // Make a function that moves cubes in a circular motion
    void MoveCubesInDonutMotion(float deltaTime, float timeSinceStartup, float speed, float radius)
    {
        for (int i = 0; i < cubes.Length; i++)
        {
            // Calculate the angle based on the current iteration and the total number of cubes
            float angle = (float)i / cubes.Length * 2 * Mathf.PI;

            // Calculate the new position based on the circular motion
            float x = Mathf.Cos(timeSinceStartup + angle) * radius;
            float z = Mathf.Sin(timeSinceStartup + angle) * radius;

            cubes[i].transform.position = new Vector3(x, 1.0f, z);
        }
    }
}
