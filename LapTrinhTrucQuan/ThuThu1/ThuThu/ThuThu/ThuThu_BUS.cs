﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;

namespace ThuThu
{
    class ThuThu_BUS
    {
        ThuThu_DAO thuThu_DAO = new ThuThu_DAO();
        public DataTable GetListThuThu()
        {
            return thuThu_DAO.loadThuThu();
        }
        public DataTable GetListThuThuNhanHSTra()
         {
             return thuThu_DAO.loadThuThuNhanHSTra();
         }
        public int Them(ThuThu_DTO tt)
        {
            /*if (string.IsNullOrEmpty(tt.MaTT))
                return 0;*/
            if (!thuThu_DAO.Insert(tt))
                return -1;
            return 1;
        }
        public bool Sua(ThuThu_DTO tt)
        {
            if (string.IsNullOrEmpty(tt.MaTT))
                return false;
            thuThu_DAO.Update(tt);
            return true;
        }
        public void Xoa(string id)
        {
            thuThu_DAO.Delete(id);
        }
        public DataTable TimKiem1(string _timkiem, string _loaitk)
        {
            return thuThu_DAO.Search1(_timkiem, _loaitk);
        }
        public DataTable TimKiem2(string _timkiem, string _loaitk)
        {
            return thuThu_DAO.Search2(_timkiem, _loaitk);
        }
    }
}
