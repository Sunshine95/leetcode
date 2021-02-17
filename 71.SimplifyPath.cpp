class Solution
{
public:
    string simplifyPath(string path)
    {
        string canonical = "";
        int n = path.size();

        int i = 0;
        while (i < n - 1)
        {

            if (path[i] == '/')
            {
                canonical += '/';
                string filename = "";
                i++;

                while (i < n && path[i] != '/')
                {
                    filename += path[i];
                    i++;
                }

                if (filename.empty())
                {
                    canonical.pop_back();
                }
                else if (filename == ".")
                {
                    canonical.pop_back();
                }
                else if (filename == "..")
                {
                    canonical.pop_back();

                    if (!canonical.empty())
                    {
                        while (canonical.back() != '/')
                            canonical.pop_back();
                        canonical.pop_back();
                    }
                }
                else
                {
                    canonical += filename;
                }
            }
        }

        if (canonical.empty())
            canonical += '/';
        return canonical;
    }
};  