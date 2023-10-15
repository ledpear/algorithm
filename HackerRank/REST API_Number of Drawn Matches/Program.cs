using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text.Json.Nodes;
using System.Text.Json;

public class ResultData
{
    public string? competition { get; set; }
    public int year { get; set; }
    public string? round { get; set; }
    public string? team1 { get; set; }
    public string? team2 { get; set; }
    public string? team1goals { get; set; }
    public string? team2goals { get; set; }
}

class Result
{

    /*
     * Complete the 'getNumDraws' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER year as parameter.
     */

    public static int getNumDraws(int year)
    {
        int total = 0;

        for (int goals = 0; goals < 10; ++goals)
        {
            //api 설정
            string targetURL = string.Format("https://jsonmock.hackerrank.com/api/football_matches?year={0}&team1goals={1}&team2goals={1}", year, goals);
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(targetURL);

            request.Method = "GET";
            request.ContentType = "application/json";

            try
            {
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();
                StreamReader responseStream = new StreamReader(response.GetResponseStream());
                string resultApi = responseStream.ReadToEnd();
                responseStream.Close();

                using (JsonDocument document = JsonDocument.Parse(resultApi))
                {
                    JsonElement root = document.RootElement;
                    JsonElement totalElement = root.GetProperty("total");
                    JsonElement dataElement = root.GetProperty("data");

                    //total += dataElement.GetArrayLength();
                    total += totalElement.GetInt32();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
        

        return total;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        //TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int result = Result.getNumDraws(2011);
        Console.WriteLine(result);
    }
}