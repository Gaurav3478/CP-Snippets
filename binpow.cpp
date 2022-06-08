ll binpow(ll b,ll p)
{
    ll r=1;
    while(p)
    {
        if(p&1)
        r=(r*b)%MOD;
        b=(b*b)%MOD;
        p/=2;
    }
    return r;
}