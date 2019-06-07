#include "strain.hpp"
#ifndef hylc_strain_II

using namespace hylc;
using namespace hylc::mathematica;

std::tuple<Mat6x18, Vec6> hylc::mathematica::strain_valgrad(
    const Vec18 &xloc, const Mat2x2 &invDm, const Real &A,
    const Real &thetarest0, const Real &thetarest1, const Real &thetarest2,
    const Real &l0, const Real &l1, const Real &l2, const Vec2 &t0,
    const Vec2 &t1, const Vec2 &t2) {
  // define output
  Mat6x18 grad(0);
  Vec6 val(0);
  auto out1 = [&](int i) -> Real & { return val[i]; };
  auto out2 = [&](int i, int j) -> Real & { return grad(i, j); };

  Real copt41   = invDm(0, 0);
  Real copt45   = xloc(0);
  Real copt49   = -copt45;
  Real copt50   = xloc(3);
  Real copt57   = copt49 + copt50;
  Real copt64   = copt41 * copt57;
  Real copt223  = invDm(1, 0);
  Real copt226  = xloc(6);
  Real copt382  = copt226 + copt49;
  Real copt385  = copt223 * copt382;
  Real copt525  = copt385 + copt64;
  Real copt526  = Power(copt525, 2);
  Real copt527  = xloc(1);
  Real copt529  = -copt527;
  Real copt530  = xloc(4);
  Real copt532  = copt529 + copt530;
  Real copt533  = copt41 * copt532;
  Real copt535  = xloc(7);
  Real copt536  = copt529 + copt535;
  Real copt537  = copt223 * copt536;
  Real copt538  = copt533 + copt537;
  Real copt540  = Power(copt538, 2);
  Real copt541  = xloc(2);
  Real copt543  = -copt541;
  Real copt544  = xloc(5);
  Real copt546  = copt543 + copt544;
  Real copt547  = copt41 * copt546;
  Real copt548  = xloc(8);
  Real copt549  = copt543 + copt548;
  Real copt550  = copt223 * copt549;
  Real copt551  = copt547 + copt550;
  Real copt552  = Power(copt551, 2);
  Real copt553  = copt526 + copt540 + copt552;
  Real copt554  = Sqrt(copt553);
  Real copt555  = 1 / copt554;
  Real copt556  = invDm(0, 1);
  Real copt558  = invDm(1, 1);
  Real copt557  = copt556 * copt57;
  Real copt559  = copt382 * copt558;
  Real copt560  = copt557 + copt559;
  Real copt571  = Power(copt560, 2);
  Real copt562  = copt532 * copt556;
  Real copt563  = copt536 * copt558;
  Real copt564  = copt562 + copt563;
  Real copt572  = Power(copt564, 2);
  Real copt566  = copt546 * copt556;
  Real copt567  = copt549 * copt558;
  Real copt568  = copt566 + copt567;
  Real copt573  = Power(copt568, 2);
  Real copt574  = copt571 + copt572 + copt573;
  Real copt575  = Sqrt(copt574);
  Real copt576  = 1 / copt575;
  Real copt578  = 1 / A;
  Real copt579  = 1 / l0;
  Real copt580  = 1 / l1;
  Real copt581  = 1 / l2;
  Real copt582  = t0(0);
  Real copt583  = Power(copt582, 2);
  Real copt585  = -copt50;
  Real copt586  = copt45 + copt585;
  Real copt587  = Power(copt586, 2);
  Real copt588  = -copt530;
  Real copt589  = copt527 + copt588;
  Real copt590  = Power(copt589, 2);
  Real copt591  = -copt544;
  Real copt592  = copt541 + copt591;
  Real copt593  = Power(copt592, 2);
  Real copt594  = copt587 + copt590 + copt593;
  Real copt595  = Sqrt(copt594);
  Real copt596  = Power(copt45, 2);
  Real copt597  = Power(copt530, 2);
  Real copt599  = Power(copt544, 2);
  Real copt607  = xloc(9);
  Real copt616  = xloc(10);
  Real copt623  = Power(copt50, 2);
  Real copt627  = Power(copt541, 2);
  Real copt636  = xloc(11);
  Real copt646  = Power(copt527, 2);
  Real copt628  = copt226 * copt607;
  Real copt629  = copt226 + copt607;
  Real copt630  = -(copt50 * copt629);
  Real copt648  = copt548 + copt636;
  Real copt662  = copt544 * copt629;
  Real copt632  = copt535 + copt616;
  Real copt668  = -2 * copt544;
  Real copt669  = copt548 + copt636 + copt668;
  Real copt686  = -(copt535 * copt607);
  Real copt661  = copt548 * copt607;
  Real copt667  = -(copt226 * copt636);
  Real copt744  = t1(0);
  Real copt745  = Power(copt744, 2);
  Real copt719  = -copt226;
  Real copt747  = copt50 + copt719;
  Real copt748  = Power(copt747, 2);
  Real copt749  = -copt535;
  Real copt750  = copt530 + copt749;
  Real copt751  = Power(copt750, 2);
  Real copt735  = -copt548;
  Real copt752  = copt544 + copt735;
  Real copt753  = Power(copt752, 2);
  Real copt754  = copt748 + copt751 + copt753;
  Real copt755  = Sqrt(copt754);
  Real copt757  = Power(copt226, 2);
  Real copt763  = Power(copt535, 2);
  Real copt773  = Power(copt548, 2);
  Real copt776  = xloc(12);
  Real copt789  = xloc(13);
  Real copt802  = xloc(14);
  Real copt820  = -copt776;
  Real copt821  = copt226 + copt820;
  Real copt829  = -copt789;
  Real copt830  = copt535 + copt829;
  Real copt837  = -copt802;
  Real copt838  = copt548 + copt837;
  Real copt711  = -(copt45 * copt535 * copt544);
  Real copt712  = copt45 * copt530 * copt548;
  Real copt855  = copt50 * copt830;
  Real copt903  = t2(0);
  Real copt904  = Power(copt903, 2);
  Real copt906  = copt45 + copt719;
  Real copt907  = Power(copt906, 2);
  Real copt908  = copt527 + copt749;
  Real copt909  = Power(copt908, 2);
  Real copt910  = copt541 + copt735;
  Real copt911  = Power(copt910, 2);
  Real copt912  = copt907 + copt909 + copt911;
  Real copt913  = Sqrt(copt912);
  Real copt922  = xloc(15);
  Real copt936  = xloc(16);
  Real copt931  = -copt757;
  Real copt932  = -copt922;
  Real copt933  = copt226 + copt932;
  Real copt934  = copt50 * copt933;
  Real copt935  = copt226 * copt922;
  Real copt951  = xloc(17);
  Real copt937  = -copt936;
  Real copt938  = copt535 + copt937;
  Real copt952  = -copt951;
  Real copt953  = copt548 + copt952;
  Real copt983  = copt50 * copt938;
  Real copt984  = copt226 * copt936;
  Real copt1008 = copt544 * copt933;
  Real copt1009 = copt548 * copt922;
  Real copt598  = copt596 * copt597;
  Real copt600  = copt596 * copt599;
  Real copt601  = -(copt226 * copt45 * copt597);
  Real copt602  = -(copt226 * copt45 * copt599);
  Real copt603  = -(copt530 * copt535 * copt596);
  Real copt604  = copt45 * copt50 * copt530 * copt535;
  Real copt605  = -(copt544 * copt548 * copt596);
  Real copt606  = copt45 * copt50 * copt544 * copt548;
  Real copt608  = -(copt45 * copt597 * copt607);
  Real copt609  = -(copt45 * copt599 * copt607);
  Real copt610  = copt226 * copt597 * copt607;
  Real copt611  = copt226 * copt599 * copt607;
  Real copt612  = copt45 * copt530 * copt535 * copt607;
  Real copt613  = -(copt50 * copt530 * copt535 * copt607);
  Real copt614  = copt45 * copt544 * copt548 * copt607;
  Real copt615  = -(copt50 * copt544 * copt548 * copt607);
  Real copt617  = -(copt530 * copt596 * copt616);
  Real copt618  = copt45 * copt50 * copt530 * copt616;
  Real copt619  = copt226 * copt45 * copt530 * copt616;
  Real copt620  = -(copt226 * copt50 * copt530 * copt616);
  Real copt621  = copt535 * copt596 * copt616;
  Real copt622  = -2 * copt45 * copt50 * copt535 * copt616;
  Real copt624  = copt535 * copt616 * copt623;
  Real copt625  = copt535 * copt599 * copt616;
  Real copt626  = -(copt530 * copt544 * copt548 * copt616);
  Real copt631  = copt535 * copt616;
  Real copt633  = -(copt530 * copt632);
  Real copt634  = copt597 + copt623 + copt628 + copt630 + copt631 + copt633;
  Real copt635  = copt627 * copt634;
  Real copt637  = -(copt544 * copt596 * copt636);
  Real copt638  = copt45 * copt50 * copt544 * copt636;
  Real copt639  = copt226 * copt45 * copt544 * copt636;
  Real copt640  = -(copt226 * copt50 * copt544 * copt636);
  Real copt641  = -(copt530 * copt535 * copt544 * copt636);
  Real copt642  = copt548 * copt596 * copt636;
  Real copt643  = -2 * copt45 * copt50 * copt548 * copt636;
  Real copt644  = copt548 * copt623 * copt636;
  Real copt645  = copt548 * copt597 * copt636;
  Real copt647  = copt548 * copt636;
  Real copt649  = -(copt544 * copt648);
  Real copt650  = copt599 + copt623 + copt628 + copt630 + copt647 + copt649;
  Real copt651  = copt646 * copt650;
  Real copt652  = copt530 * copt535 * copt544;
  Real copt653  = -(copt548 * copt597);
  Real copt654  = -2 * copt226 * copt544 * copt607;
  Real copt655  = copt530 * copt544 * copt616;
  Real copt656  = -2 * copt535 * copt544 * copt616;
  Real copt657  = copt530 * copt548 * copt616;
  Real copt658  = -(copt597 * copt636);
  Real copt659  = copt530 * copt535 * copt636;
  Real copt660  = -(copt623 * copt648);
  Real copt663  = copt226 * copt636;
  Real copt664  = copt661 + copt662 + copt663;
  Real copt665  = copt50 * copt664;
  Real copt666  = -(copt548 * copt607);
  Real copt670  = copt50 * copt669;
  Real copt671  = copt662 + copt666 + copt667 + copt670;
  Real copt672  = copt45 * copt671;
  Real copt673  = copt652 + copt653 + copt654 + copt655 + copt656 + copt657 +
                 copt658 + copt659 + copt660 + copt665 + copt672;
  Real copt674 = copt541 * copt673;
  Real copt675 = copt226 * copt50 * copt530;
  Real copt676 = -(copt535 * copt623);
  Real copt677 = -(copt535 * copt599);
  Real copt678 = copt530 * copt544 * copt548;
  Real copt679 = copt50 * copt530 * copt607;
  Real copt680 = -2 * copt226 * copt530 * copt607;
  Real copt681 = copt50 * copt535 * copt607;
  Real copt682 = -(copt616 * copt623);
  Real copt683 = -(copt599 * copt616);
  Real copt684 = copt226 * copt50 * copt616;
  Real copt685 = copt544 * copt548 * copt616;
  Real copt687 = copt530 * copt629;
  Real copt688 = -(copt226 * copt616);
  Real copt689 = -2 * copt530;
  Real copt690 = copt535 + copt616 + copt689;
  Real copt691 = copt50 * copt690;
  Real copt692 = copt686 + copt687 + copt688 + copt691;
  Real copt693 = copt45 * copt692;
  Real copt694 = copt530 * copt544 * copt636;
  Real copt695 = copt535 * copt544 * copt636;
  Real copt696 = -2 * copt530 * copt548 * copt636;
  Real copt697 = -(copt548 * copt616);
  Real copt698 = copt544 * copt632;
  Real copt699 = -(copt535 * copt636);
  Real copt700 = copt530 * copt669;
  Real copt701 = copt697 + copt698 + copt699 + copt700;
  Real copt702 = copt541 * copt701;
  Real copt703 = copt675 + copt676 + copt677 + copt678 + copt679 + copt680 +
                 copt681 + copt682 + copt683 + copt684 + copt685 + copt693 +
                 copt694 + copt695 + copt696 + copt702;
  Real copt704 = copt527 * copt703;
  Real copt705 = copt598 + copt600 + copt601 + copt602 + copt603 + copt604 +
                 copt605 + copt606 + copt608 + copt609 + copt610 + copt611 +
                 copt612 + copt613 + copt614 + copt615 + copt617 + copt618 +
                 copt619 + copt620 + copt621 + copt622 + copt624 + copt625 +
                 copt626 + copt635 + copt637 + copt638 + copt639 + copt640 +
                 copt641 + copt642 + copt643 + copt644 + copt645 + copt651 +
                 copt674 + copt704;
  Real copt706 = -(copt595 * copt705);
  Real copt707 = -2 * copt45 * copt50;
  Real copt708 = -2 * copt527 * copt530;
  Real copt709 = -2 * copt541 * copt544;
  Real copt710 = copt596 + copt597 + copt599 + copt623 + copt627 + copt646 +
                 copt707 + copt708 + copt709;
  Real copt713 = copt535 * copt544 * copt607;
  Real copt714 = -(copt530 * copt548 * copt607);
  Real copt715 = copt45 * copt544 * copt616;
  Real copt716 = -(copt226 * copt544 * copt616);
  Real copt717 = -(copt45 * copt548 * copt616);
  Real copt718 = copt50 * copt548 * copt616;
  Real copt720 = copt607 + copt719;
  Real copt721 = copt530 * copt720;
  Real copt722 = -copt616;
  Real copt723 = copt535 + copt722;
  Real copt724 = copt50 * copt723;
  Real copt725 = copt226 * copt616;
  Real copt726 = copt686 + copt721 + copt724 + copt725;
  Real copt727 = copt541 * copt726;
  Real copt728 = -(copt45 * copt530 * copt636);
  Real copt729 = copt226 * copt530 * copt636;
  Real copt730 = copt45 * copt535 * copt636;
  Real copt731 = -(copt50 * copt535 * copt636);
  Real copt732 = -copt607;
  Real copt733 = copt226 + copt732;
  Real copt734 = copt544 * copt733;
  Real copt736 = copt636 + copt735;
  Real copt737 = copt50 * copt736;
  Real copt738 = copt661 + copt667 + copt734 + copt737;
  Real copt739 = copt527 * copt738;
  Real copt740 = copt711 + copt712 + copt713 + copt714 + copt715 + copt716 +
                 copt717 + copt718 + copt727 + copt728 + copt729 + copt730 +
                 copt731 + copt739;
  Real copt741  = copt710 * copt740;
  Real copt742  = ArcTan(copt706, copt741);
  Real copt1048 = t0(1);
  Real copt756  = -(copt226 * copt50 * copt541 * copt544);
  Real copt758  = -(copt597 * copt757);
  Real copt759  = copt541 * copt544 * copt757;
  Real copt760  = -(copt599 * copt757);
  Real copt761  = -(copt530 * copt535 * copt541 * copt544);
  Real copt762  = 2 * copt226 * copt50 * copt530 * copt535;
  Real copt764  = -(copt623 * copt763);
  Real copt765  = copt541 * copt544 * copt763;
  Real copt766  = -(copt599 * copt763);
  Real copt767  = copt541 * copt548 * copt623;
  Real copt768  = copt541 * copt548 * copt597;
  Real copt769  = -(copt226 * copt50 * copt541 * copt548);
  Real copt770  = 2 * copt226 * copt50 * copt544 * copt548;
  Real copt771  = -(copt530 * copt535 * copt541 * copt548);
  Real copt772  = 2 * copt530 * copt535 * copt544 * copt548;
  Real copt774  = -(copt623 * copt773);
  Real copt775  = -(copt597 * copt773);
  Real copt777  = copt50 * copt541 * copt544 * copt776;
  Real copt778  = copt226 * copt597 * copt776;
  Real copt779  = -(copt226 * copt541 * copt544 * copt776);
  Real copt780  = copt226 * copt599 * copt776;
  Real copt781  = -(copt50 * copt530 * copt535 * copt776);
  Real copt782  = -(copt226 * copt530 * copt535 * copt776);
  Real copt783  = copt50 * copt763 * copt776;
  Real copt784  = -(copt50 * copt541 * copt548 * copt776);
  Real copt785  = -(copt50 * copt544 * copt548 * copt776);
  Real copt786  = copt226 * copt541 * copt548 * copt776;
  Real copt787  = -(copt226 * copt544 * copt548 * copt776);
  Real copt788  = copt50 * copt773 * copt776;
  Real copt790  = copt530 * copt541 * copt544 * copt789;
  Real copt791  = -(copt226 * copt50 * copt530 * copt789);
  Real copt792  = copt530 * copt757 * copt789;
  Real copt793  = copt535 * copt623 * copt789;
  Real copt794  = -(copt535 * copt541 * copt544 * copt789);
  Real copt795  = copt535 * copt599 * copt789;
  Real copt796  = -(copt226 * copt50 * copt535 * copt789);
  Real copt797  = -(copt530 * copt541 * copt548 * copt789);
  Real copt798  = -(copt530 * copt544 * copt548 * copt789);
  Real copt799  = copt535 * copt541 * copt548 * copt789;
  Real copt800  = -(copt535 * copt544 * copt548 * copt789);
  Real copt801  = copt530 * copt773 * copt789;
  Real copt803  = -(copt541 * copt623 * copt802);
  Real copt804  = -(copt541 * copt597 * copt802);
  Real copt805  = 2 * copt226 * copt50 * copt541 * copt802;
  Real copt806  = -(copt226 * copt50 * copt544 * copt802);
  Real copt807  = -(copt541 * copt757 * copt802);
  Real copt808  = copt544 * copt757 * copt802;
  Real copt809  = 2 * copt530 * copt535 * copt541 * copt802;
  Real copt810  = -(copt530 * copt535 * copt544 * copt802);
  Real copt811  = -(copt541 * copt763 * copt802);
  Real copt812  = copt544 * copt763 * copt802;
  Real copt813  = copt548 * copt623 * copt802;
  Real copt814  = copt548 * copt597 * copt802;
  Real copt815  = -(copt226 * copt50 * copt548 * copt802);
  Real copt816  = -(copt530 * copt535 * copt548 * copt802);
  Real copt817  = copt535 * copt599;
  Real copt818  = -(copt535 * copt544 * copt548);
  Real copt819  = copt226 * copt535 * copt776;
  Real copt822  = copt530 * copt821;
  Real copt823  = copt535 * copt776;
  Real copt824  = -2 * copt789;
  Real copt825  = copt535 + copt824;
  Real copt826  = copt226 * copt825;
  Real copt827  = copt822 + copt823 + copt826;
  Real copt828  = -(copt50 * copt827);
  Real copt831  = copt623 * copt830;
  Real copt832  = -(copt599 * copt789);
  Real copt833  = -(copt757 * copt789);
  Real copt834  = 2 * copt544 * copt548 * copt789;
  Real copt835  = -(copt773 * copt789);
  Real copt836  = -(copt226 * copt776);
  Real copt839  = -(copt752 * copt838);
  Real copt840  = copt757 + copt836 + copt839;
  Real copt841  = copt530 * copt840;
  Real copt842  = -(copt535 * copt544 * copt802);
  Real copt843  = copt535 * copt548 * copt802;
  Real copt844  = copt817 + copt818 + copt819 + copt828 + copt831 + copt832 +
                 copt833 + copt834 + copt835 + copt841 + copt842 + copt843;
  Real copt845 = copt527 * copt844;
  Real copt846 = copt50 * copt763;
  Real copt847 = copt50 * copt773;
  Real copt848 = copt597 * copt821;
  Real copt849 = copt599 * copt821;
  Real copt850 = -(copt763 * copt776);
  Real copt851 = -(copt773 * copt776);
  Real copt852 = -(copt50 * copt535 * copt789);
  Real copt853 = copt226 * copt535 * copt789;
  Real copt854 = -2 * copt535 * copt776;
  Real copt856 = copt535 + copt789;
  Real copt857 = copt226 * copt856;
  Real copt858 = copt854 + copt855 + copt857;
  Real copt859 = -(copt530 * copt858);
  Real copt860 = -(copt50 * copt548 * copt802);
  Real copt861 = copt226 * copt548 * copt802;
  Real copt862 = -2 * copt548 * copt776;
  Real copt863 = copt50 * copt838;
  Real copt864 = copt548 + copt802;
  Real copt865 = copt226 * copt864;
  Real copt866 = copt862 + copt863 + copt865;
  Real copt867 = -(copt544 * copt866);
  Real copt868 = copt846 + copt847 + copt848 + copt849 + copt850 + copt851 +
                 copt852 + copt853 + copt859 + copt860 + copt861 + copt867;
  Real copt869 = copt45 * copt868;
  Real copt870 = copt756 + copt758 + copt759 + copt760 + copt761 + copt762 +
                 copt764 + copt765 + copt766 + copt767 + copt768 + copt769 +
                 copt770 + copt771 + copt772 + copt774 + copt775 + copt777 +
                 copt778 + copt779 + copt780 + copt781 + copt782 + copt783 +
                 copt784 + copt785 + copt786 + copt787 + copt788 + copt790 +
                 copt791 + copt792 + copt793 + copt794 + copt795 + copt796 +
                 copt797 + copt798 + copt799 + copt800 + copt801 + copt803 +
                 copt804 + copt805 + copt806 + copt807 + copt808 + copt809 +
                 copt810 + copt811 + copt812 + copt813 + copt814 + copt815 +
                 copt816 + copt845 + copt869;
  Real copt871 = copt755 * copt870;
  Real copt872 = -2 * copt226 * copt50;
  Real copt873 = -2 * copt530 * copt535;
  Real copt874 = -2 * copt544 * copt548;
  Real copt875 = copt597 + copt599 + copt623 + copt757 + copt763 + copt773 +
                 copt872 + copt873 + copt874;
  Real copt876 = copt535 * copt544 * copt776;
  Real copt877 = -(copt530 * copt548 * copt776);
  Real copt878 = copt45 * copt544 * copt789;
  Real copt879 = -(copt226 * copt544 * copt789);
  Real copt880 = -(copt45 * copt548 * copt789);
  Real copt881 = copt50 * copt548 * copt789;
  Real copt882 = -(copt535 * copt776);
  Real copt883 = copt719 + copt776;
  Real copt884 = copt530 * copt883;
  Real copt885 = copt226 * copt789;
  Real copt886 = copt855 + copt882 + copt884 + copt885;
  Real copt887 = copt541 * copt886;
  Real copt888 = -(copt45 * copt530 * copt802);
  Real copt889 = copt226 * copt530 * copt802;
  Real copt890 = copt45 * copt535 * copt802;
  Real copt891 = -(copt50 * copt535 * copt802);
  Real copt892 = copt544 * copt821;
  Real copt893 = copt548 * copt776;
  Real copt894 = -(copt226 * copt802);
  Real copt895 = copt735 + copt802;
  Real copt896 = copt50 * copt895;
  Real copt897 = copt892 + copt893 + copt894 + copt896;
  Real copt898 = copt527 * copt897;
  Real copt899 = copt711 + copt712 + copt876 + copt877 + copt878 + copt879 +
                 copt880 + copt881 + copt887 + copt888 + copt889 + copt890 +
                 copt891 + copt898;
  Real copt900  = copt875 * copt899;
  Real copt901  = ArcTan(copt871, copt900);
  Real copt1051 = t1(1);
  Real copt914  = copt530 * copt535 * copt596;
  Real copt915  = -(copt226 * copt45 * copt530 * copt535);
  Real copt916  = -(copt596 * copt763);
  Real copt917  = copt45 * copt50 * copt763;
  Real copt918  = copt544 * copt548 * copt596;
  Real copt919  = -(copt226 * copt45 * copt544 * copt548);
  Real copt920  = -(copt596 * copt773);
  Real copt921  = copt45 * copt50 * copt773;
  Real copt923  = -(copt45 * copt530 * copt535 * copt922);
  Real copt924  = copt226 * copt530 * copt535 * copt922;
  Real copt925  = copt45 * copt763 * copt922;
  Real copt926  = -(copt50 * copt763 * copt922);
  Real copt927  = -(copt45 * copt544 * copt548 * copt922);
  Real copt928  = copt226 * copt544 * copt548 * copt922;
  Real copt929  = copt45 * copt773 * copt922;
  Real copt930  = -(copt50 * copt773 * copt922);
  Real copt939  = copt750 * copt938;
  Real copt940  = copt931 + copt934 + copt935 + copt939;
  Real copt941  = copt627 * copt940;
  Real copt942  = -(copt530 * copt596 * copt936);
  Real copt943  = 2 * copt226 * copt45 * copt530 * copt936;
  Real copt944  = -(copt530 * copt757 * copt936);
  Real copt945  = copt535 * copt596 * copt936;
  Real copt946  = -(copt45 * copt50 * copt535 * copt936);
  Real copt947  = -(copt226 * copt45 * copt535 * copt936);
  Real copt948  = copt226 * copt50 * copt535 * copt936;
  Real copt949  = copt535 * copt544 * copt548 * copt936;
  Real copt950  = -(copt530 * copt773 * copt936);
  Real copt954  = copt752 * copt953;
  Real copt955  = copt931 + copt934 + copt935 + copt954;
  Real copt956  = copt646 * copt955;
  Real copt957  = -(copt544 * copt596 * copt951);
  Real copt958  = 2 * copt226 * copt45 * copt544 * copt951;
  Real copt959  = -(copt544 * copt757 * copt951);
  Real copt960  = -(copt544 * copt763 * copt951);
  Real copt961  = copt548 * copt596 * copt951;
  Real copt962  = -(copt45 * copt50 * copt548 * copt951);
  Real copt963  = -(copt226 * copt45 * copt548 * copt951);
  Real copt964  = copt226 * copt50 * copt548 * copt951;
  Real copt965  = copt530 * copt535 * copt548 * copt951;
  Real copt966  = -(copt530 * copt757);
  Real copt967  = copt535 * copt541 * copt544;
  Real copt968  = copt226 * copt50 * copt535;
  Real copt969  = -2 * copt535 * copt541 * copt548;
  Real copt970  = copt535 * copt544 * copt548;
  Real copt971  = copt226 * copt530 * copt922;
  Real copt972  = -2 * copt50 * copt535 * copt922;
  Real copt973  = copt226 * copt535 * copt922;
  Real copt974  = -(copt541 * copt544 * copt936);
  Real copt975  = copt226 * copt50 * copt936;
  Real copt976  = -(copt757 * copt936);
  Real copt977  = copt541 * copt548 * copt936;
  Real copt978  = copt544 * copt548 * copt936;
  Real copt979  = -(copt773 * copt936);
  Real copt980  = -2 * copt226 * copt535;
  Real copt981  = copt530 * copt933;
  Real copt982  = copt535 * copt922;
  Real copt985  = copt980 + copt981 + copt982 + copt983 + copt984;
  Real copt986  = copt45 * copt985;
  Real copt987  = copt530 * copt910 * copt953;
  Real copt988  = copt535 * copt541 * copt951;
  Real copt989  = -2 * copt535 * copt544 * copt951;
  Real copt990  = copt535 * copt548 * copt951;
  Real copt991  = copt966 + copt967 + copt968 + copt969 + copt970 + copt971 +
                 copt972 + copt973 + copt974 + copt975 + copt976 + copt977 +
                 copt978 + copt979 + copt986 + copt987 + copt988 + copt989 +
                 copt990;
  Real copt992  = -(copt527 * copt991);
  Real copt993  = copt226 * copt50 * copt548;
  Real copt994  = copt530 * copt535 * copt548;
  Real copt995  = -2 * copt50 * copt548 * copt922;
  Real copt996  = copt226 * copt548 * copt922;
  Real copt997  = -2 * copt530 * copt548 * copt936;
  Real copt998  = copt535 * copt548 * copt936;
  Real copt999  = -(copt226 * copt922);
  Real copt1000 = -(copt535 * copt936);
  Real copt1001 = copt1000 + copt757 + copt763 + copt999;
  Real copt1002 = -(copt1001 * copt544);
  Real copt1003 = copt226 * copt50 * copt951;
  Real copt1004 = -(copt757 * copt951);
  Real copt1005 = copt530 * copt535 * copt951;
  Real copt1006 = -(copt763 * copt951);
  Real copt1007 = -2 * copt226 * copt548;
  Real copt1010 = copt50 * copt953;
  Real copt1011 = copt226 * copt951;
  Real copt1012 = copt1007 + copt1008 + copt1009 + copt1010 + copt1011;
  Real copt1013 = copt1012 * copt45;
  Real copt1014 = copt1002 + copt1003 + copt1004 + copt1005 + copt1006 +
                  copt1013 + copt993 + copt994 + copt995 + copt996 + copt997 +
                  copt998;
  Real copt1015 = -(copt1014 * copt541);
  Real copt1016 = copt1015 + copt914 + copt915 + copt916 + copt917 + copt918 +
                  copt919 + copt920 + copt921 + copt923 + copt924 + copt925 +
                  copt926 + copt927 + copt928 + copt929 + copt930 + copt941 +
                  copt942 + copt943 + copt944 + copt945 + copt946 + copt947 +
                  copt948 + copt949 + copt950 + copt956 + copt957 + copt958 +
                  copt959 + copt960 + copt961 + copt962 + copt963 + copt964 +
                  copt965 + copt992;
  Real copt1017 = copt1016 * copt913;
  Real copt1018 = -2 * copt226 * copt45;
  Real copt1019 = -2 * copt527 * copt535;
  Real copt1020 = -2 * copt541 * copt548;
  Real copt1021 = copt1018 + copt1019 + copt1020 + copt596 + copt627 + copt646 +
                  copt757 + copt763 + copt773;
  Real copt1022 = copt535 * copt544 * copt922;
  Real copt1023 = -(copt530 * copt548 * copt922);
  Real copt1024 = copt45 * copt544 * copt936;
  Real copt1025 = -(copt226 * copt544 * copt936);
  Real copt1026 = -(copt45 * copt548 * copt936);
  Real copt1027 = copt50 * copt548 * copt936;
  Real copt1028 = -(copt535 * copt922);
  Real copt1029 = copt719 + copt922;
  Real copt1030 = copt1029 * copt530;
  Real copt1031 = copt1028 + copt1030 + copt983 + copt984;
  Real copt1032 = copt1031 * copt541;
  Real copt1033 = -(copt45 * copt530 * copt951);
  Real copt1034 = copt226 * copt530 * copt951;
  Real copt1035 = copt45 * copt535 * copt951;
  Real copt1036 = -(copt50 * copt535 * copt951);
  Real copt1037 = -(copt226 * copt951);
  Real copt1038 = copt735 + copt951;
  Real copt1039 = copt1038 * copt50;
  Real copt1040 = copt1008 + copt1009 + copt1037 + copt1039;
  Real copt1041 = copt1040 * copt527;
  Real copt1042 = copt1022 + copt1023 + copt1024 + copt1025 + copt1026 +
                  copt1027 + copt1032 + copt1033 + copt1034 + copt1035 +
                  copt1036 + copt1041 + copt711 + copt712;
  Real copt1043 = copt1021 * copt1042;
  Real copt1044 = ArcTan(copt1017, copt1043);
  Real copt1054 = t2(1);
  Real copt1059 = Power(copt1048, 2);
  Real copt1062 = Power(copt1051, 2);
  Real copt1065 = Power(copt1054, 2);
  Real copt1070 = copt223 + copt41;
  Real copt1089 = copt553 * copt554;
  Real copt1090 = 1 / copt1089;
  Real copt1091 = copt574 * copt575;
  Real copt1092 = 1 / copt1091;
  Real copt561  = copt525 * copt560;
  Real copt565  = copt538 * copt564;
  Real copt569  = copt551 * copt568;
  Real copt570  = copt561 + copt565 + copt569;
  Real copt1093 = copt556 + copt558;
  Real copt1071 = copt41 * copt586;
  Real copt1072 = copt223 * copt906;
  Real copt1073 = copt1071 + copt1072;
  Real copt1075 = copt41 * copt589;
  Real copt1076 = copt223 * copt908;
  Real copt1077 = copt1075 + copt1076;
  Real copt1079 = copt41 * copt592;
  Real copt1080 = copt223 * copt910;
  Real copt1081 = copt1079 + copt1080;
  Real copt1096 = copt556 * copt586;
  Real copt1097 = copt558 * copt906;
  Real copt1098 = copt1096 + copt1097;
  Real copt1107 = copt556 * copt589;
  Real copt1108 = copt558 * copt908;
  Real copt1109 = copt1107 + copt1108;
  Real copt1118 = copt556 * copt592;
  Real copt1119 = copt558 * copt910;
  Real copt1120 = copt1118 + copt1119;
  Real copt1206 = Power(copt710, 2);
  Real copt1207 = Power(copt740, 2);
  Real copt1208 = copt1206 * copt1207;
  Real copt1209 = Power(copt705, 2);
  Real copt1210 = copt1209 * copt594;
  Real copt1211 = copt1208 + copt1210;
  Real copt1212 = 1 / copt1211;
  Real copt1214 = 1 / copt595;
  Real copt1246 = Power(copt875, 2);
  Real copt1247 = Power(copt899, 2);
  Real copt1248 = copt1246 * copt1247;
  Real copt1249 = Power(copt870, 2);
  Real copt1250 = copt1249 * copt754;
  Real copt1251 = copt1248 + copt1250;
  Real copt1252 = 1 / copt1251;
  Real copt1273 = Power(copt1021, 2);
  Real copt1274 = Power(copt1042, 2);
  Real copt1275 = copt1273 * copt1274;
  Real copt1276 = copt226 * copt45 * copt530 * copt535;
  Real copt1277 = copt596 * copt763;
  Real copt1278 = -(copt45 * copt50 * copt763);
  Real copt1279 = copt226 * copt45 * copt544 * copt548;
  Real copt1280 = copt596 * copt773;
  Real copt1281 = -(copt45 * copt50 * copt773);
  Real copt1282 = copt45 * copt530 * copt535 * copt922;
  Real copt1283 = -(copt226 * copt530 * copt535 * copt922);
  Real copt1284 = -(copt45 * copt763 * copt922);
  Real copt1285 = copt50 * copt763 * copt922;
  Real copt1286 = copt45 * copt544 * copt548 * copt922;
  Real copt1287 = -(copt226 * copt544 * copt548 * copt922);
  Real copt1288 = -(copt45 * copt773 * copt922);
  Real copt1289 = copt50 * copt773 * copt922;
  Real copt1290 = -(copt627 * copt940);
  Real copt1291 = copt530 * copt596 * copt936;
  Real copt1292 = -2 * copt226 * copt45 * copt530 * copt936;
  Real copt1293 = copt530 * copt757 * copt936;
  Real copt1294 = -(copt535 * copt596 * copt936);
  Real copt1295 = copt45 * copt50 * copt535 * copt936;
  Real copt1296 = copt226 * copt45 * copt535 * copt936;
  Real copt1297 = -(copt226 * copt50 * copt535 * copt936);
  Real copt1298 = -(copt535 * copt544 * copt548 * copt936);
  Real copt1299 = copt530 * copt773 * copt936;
  Real copt1300 = -(copt646 * copt955);
  Real copt1301 = copt544 * copt596 * copt951;
  Real copt1302 = -2 * copt226 * copt45 * copt544 * copt951;
  Real copt1303 = copt544 * copt757 * copt951;
  Real copt1304 = copt544 * copt763 * copt951;
  Real copt1305 = -(copt548 * copt596 * copt951);
  Real copt1306 = copt45 * copt50 * copt548 * copt951;
  Real copt1307 = copt226 * copt45 * copt548 * copt951;
  Real copt1308 = -(copt226 * copt50 * copt548 * copt951);
  Real copt1309 = -(copt530 * copt535 * copt548 * copt951);
  Real copt1310 = copt527 * copt991;
  Real copt1311 = copt535 * copt938;
  Real copt1312 = copt1311 + copt757 + copt999;
  Real copt1313 = -(copt1312 * copt544);
  Real copt1314 = copt1003 + copt1004 + copt1005 + copt1006 + copt1013 +
                  copt1313 + copt993 + copt994 + copt995 + copt996 + copt997 +
                  copt998;
  Real copt1315 = copt1314 * copt541;
  Real copt1316 = copt1276 + copt1277 + copt1278 + copt1279 + copt1280 +
                  copt1281 + copt1282 + copt1283 + copt1284 + copt1285 +
                  copt1286 + copt1287 + copt1288 + copt1289 + copt1290 +
                  copt1291 + copt1292 + copt1293 + copt1294 + copt1295 +
                  copt1296 + copt1297 + copt1298 + copt1299 + copt1300 +
                  copt1301 + copt1302 + copt1303 + copt1304 + copt1305 +
                  copt1306 + copt1307 + copt1308 + copt1309 + copt1310 +
                  copt1315 + copt603 + copt605;
  Real copt1317 = Power(copt1316, 2);
  Real copt1318 = copt1317 * copt912;
  Real copt1319 = copt1275 + copt1318;
  Real copt1320 = 1 / copt1319;
  Real copt1322 = 1 / copt913;
  Real copt1355 = 2 * copt527;
  Real copt1407 = 2 * copt541;
  Real copt1427 = -(copt226 * copt50 * copt548);
  Real copt1428 = -(copt530 * copt535 * copt548);
  Real copt1267 = copt530 * copt953;
  Real copt1268 = copt535 * copt951;
  Real copt1486 = 2 * copt50;
  Real copt1493 = copt1486 + copt719 + copt732;
  Real copt1570 = 1 / copt755;
  Real copt1468 = copt548 * copt936;
  Real copt1613 = 2 * copt530;
  Real copt1465 = copt535 * copt544;
  Real copt1481 = copt548 * copt616;
  Real copt1201 = copt535 * copt636;
  Real copt1607 = copt45 * copt548;
  Real copt1373 = -2 * copt535;
  Real copt1379 = -(copt535 * copt541 * copt544);
  Real copt1505 = copt535 * copt607;
  Real copt1643 = -2 * copt226 * copt607;
  Real copt1644 = -2 * copt50;
  Real copt1645 = copt1644 + copt226 + copt607;
  Real copt1646 = copt1645 * copt45;
  Real copt1735 = 2 * copt544;
  Real copt1198 = -copt636;
  Real copt1255 = copt530 * copt548;
  Real copt1729 = -(copt45 * copt535);
  Real copt1449 = -2 * copt548;
  Real copt1431 = -(copt50 * copt548 * copt776);
  Real copt1435 = -(copt530 * copt548 * copt789);
  Real copt1527 = -(copt535 * copt802);
  Real copt1710 = copt45 * copt933;
  Real copt1714 = copt535 * copt548;
  Real copt1855 = copt585 + copt607;
  Real copt1498 = copt45 * copt530 * copt616;
  Real copt1510 = copt45 * copt544 * copt636;
  Real copt1868 = copt1198 + copt544;
  Real copt1766 = copt530 * copt636;
  Real copt1544 = -(copt530 * copt535 * copt776);
  Real copt1547 = -(copt544 * copt548 * copt776);
  Real copt1892 = 2 * copt226;
  Real copt1467 = -(copt544 * copt936);
  Real copt1485 = -2 * copt45;
  Real copt1531 = -2 * copt226;
  Real copt1949 = copt1531 + copt50 + copt922;
  Real copt1582 = -(copt45 * copt535 * copt936);
  Real copt1589 = -(copt45 * copt548 * copt951);
  Real copt1877 = copt588 + copt616;
  Real copt1764 = -2 * copt544 * copt616;
  Real copt1642 = copt50 * copt607;
  Real copt1647 = copt544 * copt636;
  Real copt2000 = copt50 + copt732;
  Real copt2007 = -(copt45 * copt544);
  Real copt1679 = -(copt226 * copt50 * copt789);
  Real copt1682 = -(copt544 * copt548 * copt789);
  Real copt1923 = copt548 * copt802;
  Real copt1612 = -2 * copt527;
  Real copt2023 = 2 * copt535;
  Real copt1960 = copt1373 + copt530 + copt936;
  Real copt1938 = copt530 * copt951;
  Real copt1837 = -2 * copt535 * copt951;
  Real copt1640 = copt226 * copt50;
  Real copt1641 = copt544 * copt548;
  Real copt1998 = -copt623;
  Real copt2001 = copt2000 * copt45;
  Real copt1752 = copt530 * copt616;
  Real copt1995 = copt530 * copt544;
  Real copt1861 = copt530 + copt722;
  Real copt1636 = copt544 * copt616;
  Real copt1637 = -2 * copt530 * copt636;
  Real copt1863 = copt50 * copt616;
  Real copt2130 = copt45 * copt530;
  Real copt1785 = -(copt226 * copt50 * copt541);
  Real copt1788 = -(copt530 * copt535 * copt541);
  Real copt1430 = -(copt226 * copt544 * copt776);
  Real copt1434 = -(copt535 * copt544 * copt789);
  Real copt1801 = -(copt226 * copt50 * copt802);
  Real copt1803 = -(copt530 * copt535 * copt802);
  Real copt2043 = -2 * copt776;
  Real copt2044 = copt2043 + copt226 + copt50;
  Real copt2020 = -(copt50 * copt802);
  Real copt1662 = copt226 * copt802;
  Real copt1254 = -(copt535 * copt544);
  Real copt2145 = 2 * copt548;
  Real copt1259 = copt535 * copt802;
  Real copt1958 = copt50 * copt936;
  Real copt1734 = -2 * copt541;
  Real copt1750 = copt530 * copt535;
  Real copt2095 = -2 * copt50 * copt922;
  Real copt2096 = copt1949 * copt45;
  Real copt1829 = copt535 * copt936;
  Real copt1972 = copt1449 + copt544 + copt951;
  Real copt1715 = -2 * copt548 * copt936;
  Real copt1851 = -(copt45 * copt597);
  Real copt1852 = -(copt45 * copt599);
  Real copt2226 = copt226 + copt585;
  Real copt1491 = copt45 * copt530 * copt535;
  Real copt1859 = copt50 * copt530;
  Real copt1955 = -2 * copt226 * copt530;
  Real copt1956 = copt50 * copt535;
  Real copt1492 = copt45 * copt544 * copt548;
  Real copt1985 = -(copt530 * copt596);
  Real copt1986 = copt45 * copt50 * copt530;
  Real copt1704 = copt535 * copt596;
  Real copt1763 = -2 * copt535 * copt544;
  Real copt1999 = -copt599;
  Real copt1967 = copt50 * copt548;
  Real copt2111 = -(copt544 * copt596);
  Real copt2112 = copt45 * copt50 * copt544;
  Real copt1421 = -(copt226 * copt50 * copt544);
  Real copt1423 = -(copt530 * copt535 * copt544);
  Real copt2116 = -copt597;
  Real copt2259 = copt45 * copt747;
  Real copt1825 = copt548 * copt596;
  Real copt1425 = copt548 * copt623;
  Real copt1426 = copt548 * copt597;
  Real copt2244 = copt548 + copt591;
  Real copt2242 = copt541 * copt750;
  Real copt1635 = -2 * copt530 * copt548;
  Real copt1502 = copt226 * copt530;
  Real copt2224 = copt226 * copt597;
  Real copt1536 = -(copt226 * copt541 * copt544);
  Real copt2225 = copt226 * copt599;
  Real copt2229 = -(copt50 * copt530 * copt535);
  Real copt1324 = -(copt226 * copt530 * copt535);
  Real copt1584 = copt226 * copt535;
  Real copt2254 = copt535 + copt588;
  Real copt1902 = -(copt50 * copt541 * copt548);
  Real copt2233 = -(copt50 * copt544 * copt548);
  Real copt1327 = -(copt226 * copt544 * copt548);
  Real copt1828 = -copt763;
  Real copt2243 = -(copt530 * copt548);
  Real copt2245 = copt2244 * copt527;
  Real copt2246 = copt1465 + copt2242 + copt2243 + copt2245;
  Real copt2251 = -(copt226 * copt50 * copt530);
  Real copt1378 = copt530 * copt757;
  Real copt2253 = copt535 * copt623;
  Real copt1380 = -(copt226 * copt50 * copt535);
  Real copt2285 = -(copt50 * copt535);
  Real copt2033 = -(copt530 * copt541 * copt548);
  Real copt2256 = -(copt530 * copt544 * copt548);
  Real copt2297 = 2 * copt544 * copt548;
  Real copt2298 = -copt773;
  Real copt2265 = copt45 * copt544;
  Real copt2266 = -(copt226 * copt544);
  Real copt2267 = copt2226 * copt541;
  Real copt2268 = -(copt45 * copt548);
  Real copt2269 = copt1967 + copt2265 + copt2266 + copt2267 + copt2268;
  Real copt1422 = copt544 * copt757;
  Real copt1424 = copt544 * copt763;
  Real copt1591 = copt226 * copt548;
  Real copt2282 = -(copt45 * copt530);
  Real copt2283 = copt527 * copt747;
  Real copt2284 = copt45 * copt535;
  Real copt2286 = copt1502 + copt2282 + copt2283 + copt2284 + copt2285;
  Real copt2227 = copt2226 * copt646;
  Real copt2228 = copt2226 * copt627;
  Real copt1945 = -(copt45 * copt530 * copt535);
  Real copt1576 = copt45 * copt763;
  Real copt1503 = -2 * copt50 * copt535;
  Real copt1946 = -(copt45 * copt544 * copt548);
  Real copt1577 = copt45 * copt773;
  Real copt1705 = -(copt226 * copt45 * copt535);
  Real copt2255 = copt2254 * copt627;
  Real copt2361 = copt2226 * copt45;
  Real copt1826 = -(copt226 * copt45 * copt548);
  Real copt2277 = copt2244 * copt646;
  Real copt1835 = copt535 * copt541;
  Real copt1196 = copt616 + copt749;
  Real copt1197 = copt1196 * copt544;
  Real copt1199 = copt1198 + copt548;
  Real copt1200 = copt1199 * copt530;
  Real copt1202 = copt1197 + copt1200 + copt1201 + copt697;
  Real copt1203 = copt1202 * copt710;
  Real copt1204 = 2 * copt586 * copt740;
  Real copt1205 = copt1203 + copt1204;
  Real copt1213 = -(copt1205 * copt1212 * copt595 * copt705);
  Real copt1215 = -2 * copt50 * copt541 * copt544;
  Real copt1216 = -(copt226 * copt597);
  Real copt1217 = copt226 * copt541 * copt544;
  Real copt1218 = -(copt226 * copt599);
  Real copt1219 = copt50 * copt530 * copt535;
  Real copt1220 = copt50 * copt541 * copt548;
  Real copt1221 = copt50 * copt544 * copt548;
  Real copt1222 = -(copt597 * copt607);
  Real copt1223 = copt541 * copt544 * copt607;
  Real copt1224 = -(copt599 * copt607);
  Real copt1225 = copt530 * copt535 * copt607;
  Real copt1226 = -(copt541 * copt548 * copt607);
  Real copt1227 = copt544 * copt548 * copt607;
  Real copt1228 = copt50 * copt530 * copt616;
  Real copt1229 = copt226 * copt530 * copt616;
  Real copt1230 = -2 * copt50 * copt535 * copt616;
  Real copt1231 = copt527 * copt692;
  Real copt1232 = copt50 * copt541 * copt636;
  Real copt1233 = copt50 * copt544 * copt636;
  Real copt1234 = -(copt226 * copt541 * copt636);
  Real copt1235 = copt226 * copt544 * copt636;
  Real copt1236 = -2 * copt50 * copt548 * copt636;
  Real copt1237 = copt597 + copt599 + copt631 + copt633 + copt647 + copt649;
  Real copt1238 = 2 * copt1237 * copt45;
  Real copt1239 = copt1215 + copt1216 + copt1217 + copt1218 + copt1219 +
                  copt1220 + copt1221 + copt1222 + copt1223 + copt1224 +
                  copt1225 + copt1226 + copt1227 + copt1228 + copt1229 +
                  copt1230 + copt1231 + copt1232 + copt1233 + copt1234 +
                  copt1235 + copt1236 + copt1238;
  Real copt1240 = -(copt1239 * copt594);
  Real copt1241 = -(copt586 * copt705);
  Real copt1242 = copt1240 + copt1241;
  Real copt1243 = -(copt1212 * copt1214 * copt1242 * copt710 * copt740);
  Real copt1244 = copt1213 + copt1243;
  Real copt1253 = -(copt1252 * copt755 * copt868 * copt875 * copt899);
  Real copt1256 = copt544 * copt789;
  Real copt1257 = -(copt548 * copt789);
  Real copt1258 = -(copt530 * copt802);
  Real copt1260 =
      copt1254 + copt1255 + copt1256 + copt1257 + copt1258 + copt1259;
  Real copt1261 = copt1252 * copt1260 * copt755 * copt870 * copt875;
  Real copt1262 = copt1253 + copt1261;
  Real copt1264 = -(copt548 * copt936);
  Real copt1265 = copt749 + copt936;
  Real copt1266 = copt1265 * copt544;
  Real copt1269 = copt1264 + copt1266 + copt1267 + copt1268;
  Real copt1270 = copt1021 * copt1269;
  Real copt1271 = 2 * copt1042 * copt906;
  Real copt1272 = copt1270 + copt1271;
  Real copt1321 = copt1016 * copt1272 * copt1320 * copt913;
  Real copt1323 = 2 * copt45 * copt530 * copt535;
  Real copt1325 = -2 * copt45 * copt763;
  Real copt1326 = 2 * copt45 * copt544 * copt548;
  Real copt1328 = -2 * copt45 * copt773;
  Real copt1329 = -(copt530 * copt535 * copt922);
  Real copt1330 = copt763 * copt922;
  Real copt1331 = -(copt544 * copt548 * copt922);
  Real copt1332 = copt773 * copt922;
  Real copt1333 = -2 * copt45 * copt530 * copt936;
  Real copt1334 = 2 * copt226 * copt530 * copt936;
  Real copt1335 = 2 * copt45 * copt535 * copt936;
  Real copt1336 = -(copt50 * copt535 * copt936);
  Real copt1337 = -(copt226 * copt535 * copt936);
  Real copt1338 = -(copt527 * copt985);
  Real copt1339 = -2 * copt45 * copt544 * copt951;
  Real copt1340 = 2 * copt226 * copt544 * copt951;
  Real copt1341 = 2 * copt45 * copt548 * copt951;
  Real copt1342 = -(copt50 * copt548 * copt951);
  Real copt1343 = -(copt226 * copt548 * copt951);
  Real copt1344 = -(copt1012 * copt541);
  Real copt1345 = copt1323 + copt1324 + copt1325 + copt1326 + copt1327 +
                  copt1328 + copt1329 + copt1330 + copt1331 + copt1332 +
                  copt1333 + copt1334 + copt1335 + copt1336 + copt1337 +
                  copt1338 + copt1339 + copt1340 + copt1341 + copt1342 +
                  copt1343 + copt1344 + copt846 + copt847;
  Real copt1346 = copt1345 * copt912;
  Real copt1347 = copt1016 * copt906;
  Real copt1348 = copt1346 + copt1347;
  Real copt1349 = -(copt1021 * copt1042 * copt1320 * copt1322 * copt1348);
  Real copt1350 = copt1321 + copt1349;
  Real copt1354 = copt710 * copt738;
  Real copt1356 = copt1355 + copt689;
  Real copt1357 = copt1356 * copt740;
  Real copt1358 = copt1354 + copt1357;
  Real copt1359 = -(copt1212 * copt1358 * copt595 * copt705);
  Real copt1360 = 2 * copt527 * copt650;
  Real copt1361 = copt1360 + copt675 + copt676 + copt677 + copt678 + copt679 +
                  copt680 + copt681 + copt682 + copt683 + copt684 + copt685 +
                  copt693 + copt694 + copt695 + copt696 + copt702;
  Real copt1362 = -(copt1361 * copt595);
  Real copt1363 = -(copt1214 * copt589 * copt705);
  Real copt1364 = copt1362 + copt1363;
  Real copt1365 = -(copt1212 * copt1364 * copt710 * copt740);
  Real copt1366 = copt1359 + copt1365;
  Real copt1368 = -(copt1252 * copt755 * copt844 * copt875 * copt899);
  Real copt1369 = copt1252 * copt755 * copt870 * copt875 * copt897;
  Real copt1370 = copt1368 + copt1369;
  Real copt1372 = copt1021 * copt1040;
  Real copt1374 = copt1355 + copt1373;
  Real copt1375 = copt1042 * copt1374;
  Real copt1376 = copt1372 + copt1375;
  Real copt1377 = copt1016 * copt1320 * copt1376 * copt913;
  Real copt1381 = 2 * copt535 * copt541 * copt548;
  Real copt1382 = -(copt226 * copt530 * copt922);
  Real copt1383 = 2 * copt50 * copt535 * copt922;
  Real copt1384 = -(copt226 * copt535 * copt922);
  Real copt1385 = copt541 * copt544 * copt936;
  Real copt1386 = -(copt226 * copt50 * copt936);
  Real copt1387 = copt757 * copt936;
  Real copt1388 = -(copt541 * copt548 * copt936);
  Real copt1389 = -(copt544 * copt548 * copt936);
  Real copt1390 = copt773 * copt936;
  Real copt1391 = -(copt45 * copt985);
  Real copt1392 = 2 * copt527 * copt955;
  Real copt1393 = -(copt530 * copt910 * copt953);
  Real copt1394 = -(copt535 * copt541 * copt951);
  Real copt1395 = 2 * copt535 * copt544 * copt951;
  Real copt1396 = -(copt535 * copt548 * copt951);
  Real copt1397 = copt1378 + copt1379 + copt1380 + copt1381 + copt1382 +
                  copt1383 + copt1384 + copt1385 + copt1386 + copt1387 +
                  copt1388 + copt1389 + copt1390 + copt1391 + copt1392 +
                  copt1393 + copt1394 + copt1395 + copt1396 + copt818;
  Real copt1398 = copt1397 * copt913;
  Real copt1399 = copt1016 * copt1322 * copt908;
  Real copt1400 = copt1398 + copt1399;
  Real copt1401 = -(copt1021 * copt1042 * copt1320 * copt1400);
  Real copt1402 = copt1377 + copt1401;
  Real copt1406 = copt710 * copt726;
  Real copt1408 = copt1407 + copt668;
  Real copt1409 = copt1408 * copt740;
  Real copt1410 = copt1406 + copt1409;
  Real copt1411 = -(copt1212 * copt1410 * copt595 * copt705);
  Real copt1412 = 2 * copt541 * copt634;
  Real copt1413 = copt527 * copt701;
  Real copt1414 = copt1412 + copt1413 + copt652 + copt653 + copt654 + copt655 +
                  copt656 + copt657 + copt658 + copt659 + copt660 + copt665 +
                  copt672;
  Real copt1415 = -(copt1414 * copt595);
  Real copt1416 = -(copt1214 * copt592 * copt705);
  Real copt1417 = copt1415 + copt1416;
  Real copt1418 = -(copt1212 * copt1417 * copt710 * copt740);
  Real copt1419 = copt1411 + copt1418;
  Real copt1429 = copt50 * copt544 * copt776;
  Real copt1432 = copt226 * copt548 * copt776;
  Real copt1433 = copt530 * copt544 * copt789;
  Real copt1436 = copt535 * copt548 * copt789;
  Real copt1437 = -(copt623 * copt802);
  Real copt1438 = -(copt597 * copt802);
  Real copt1439 = 2 * copt226 * copt50 * copt802;
  Real copt1440 = -(copt757 * copt802);
  Real copt1441 = 2 * copt530 * copt535 * copt802;
  Real copt1442 = -(copt763 * copt802);
  Real copt1443 = copt1421 + copt1422 + copt1423 + copt1424 + copt1425 +
                  copt1426 + copt1427 + copt1428 + copt1429 + copt1430 +
                  copt1431 + copt1432 + copt1433 + copt1434 + copt1435 +
                  copt1436 + copt1437 + copt1438 + copt1439 + copt1440 +
                  copt1441 + copt1442;
  Real copt1444 = -(copt1252 * copt1443 * copt755 * copt875 * copt899);
  Real copt1445 = copt1252 * copt755 * copt870 * copt875 * copt886;
  Real copt1446 = copt1444 + copt1445;
  Real copt1448 = copt1021 * copt1031;
  Real copt1450 = copt1407 + copt1449;
  Real copt1451 = copt1042 * copt1450;
  Real copt1452 = copt1448 + copt1451;
  Real copt1453 = copt1016 * copt1320 * copt1452 * copt913;
  Real copt1454 = 2 * copt50 * copt548 * copt922;
  Real copt1455 = -(copt226 * copt548 * copt922);
  Real copt1456 = 2 * copt541 * copt940;
  Real copt1457 = 2 * copt530 * copt548 * copt936;
  Real copt1458 = -(copt535 * copt548 * copt936);
  Real copt1459 = copt1001 * copt544;
  Real copt1460 = -(copt226 * copt50 * copt951);
  Real copt1461 = copt757 * copt951;
  Real copt1462 = -(copt530 * copt535 * copt951);
  Real copt1463 = copt763 * copt951;
  Real copt1464 = -(copt1012 * copt45);
  Real copt1466 = -2 * copt535 * copt548;
  Real copt1469 =
      copt1267 + copt1268 + copt1465 + copt1466 + copt1467 + copt1468;
  Real copt1470 = -(copt1469 * copt527);
  Real copt1471 = copt1427 + copt1428 + copt1454 + copt1455 + copt1456 +
                  copt1457 + copt1458 + copt1459 + copt1460 + copt1461 +
                  copt1462 + copt1463 + copt1464 + copt1470;
  Real copt1472 = copt1471 * copt913;
  Real copt1473 = copt1016 * copt1322 * copt910;
  Real copt1474 = copt1472 + copt1473;
  Real copt1475 = -(copt1021 * copt1042 * copt1320 * copt1474);
  Real copt1476 = copt1453 + copt1475;
  Real copt1480 = copt541 * copt723;
  Real copt1482 = copt527 * copt736;
  Real copt1483 = copt1480 + copt1481 + copt1482 + copt699;
  Real copt1484 = copt1483 * copt710;
  Real copt1487 = copt1485 + copt1486;
  Real copt1488 = copt1487 * copt740;
  Real copt1489 = copt1484 + copt1488;
  Real copt1490 = -(copt1212 * copt1489 * copt595 * copt705);
  Real copt1494 = copt1493 * copt646;
  Real copt1495 = copt1493 * copt627;
  Real copt1496 = -(copt530 * copt535 * copt607);
  Real copt1497 = -(copt544 * copt548 * copt607);
  Real copt1499 = -(copt226 * copt530 * copt616);
  Real copt1500 = -2 * copt45 * copt535 * copt616;
  Real copt1501 = 2 * copt50 * copt535 * copt616;
  Real copt1504 = copt530 * copt607;
  Real copt1506 = -2 * copt50 * copt616;
  Real copt1507 = copt45 * copt690;
  Real copt1508 =
      copt1502 + copt1503 + copt1504 + copt1505 + copt1506 + copt1507 + copt725;
  Real copt1509 = copt1508 * copt527;
  Real copt1511 = -(copt226 * copt544 * copt636);
  Real copt1512 = -2 * copt45 * copt548 * copt636;
  Real copt1513 = 2 * copt50 * copt548 * copt636;
  Real copt1514 = -2 * copt50 * copt648;
  Real copt1515 = copt45 * copt669;
  Real copt1516 = copt1514 + copt1515 + copt661 + copt662 + copt663;
  Real copt1517 = copt1516 * copt541;
  Real copt1518 = copt1491 + copt1492 + copt1494 + copt1495 + copt1496 +
                  copt1497 + copt1498 + copt1499 + copt1500 + copt1501 +
                  copt1509 + copt1510 + copt1511 + copt1512 + copt1513 +
                  copt1517;
  Real copt1519 = -(copt1518 * copt595);
  Real copt1520 = copt1214 * copt586 * copt705;
  Real copt1521 = copt1519 + copt1520;
  Real copt1522 = -(copt1212 * copt1521 * copt710 * copt740);
  Real copt1523 = copt1490 + copt1522;
  Real copt1525 = copt541 * copt830;
  Real copt1526 = copt548 * copt789;
  Real copt1528 = copt527 * copt895;
  Real copt1529 = copt1525 + copt1526 + copt1527 + copt1528;
  Real copt1530 = copt1529 * copt875;
  Real copt1532 = copt1486 + copt1531;
  Real copt1533 = copt1532 * copt899;
  Real copt1534 = copt1530 + copt1533;
  Real copt1535 = copt1252 * copt1534 * copt755 * copt870;
  Real copt1537 = 2 * copt226 * copt530 * copt535;
  Real copt1538 = -2 * copt50 * copt763;
  Real copt1539 = 2 * copt50 * copt541 * copt548;
  Real copt1540 = -(copt226 * copt541 * copt548);
  Real copt1541 = 2 * copt226 * copt544 * copt548;
  Real copt1542 = -2 * copt50 * copt773;
  Real copt1543 = copt541 * copt544 * copt776;
  Real copt1545 = copt763 * copt776;
  Real copt1546 = -(copt541 * copt548 * copt776);
  Real copt1548 = copt773 * copt776;
  Real copt1549 = -(copt530 * copt821);
  Real copt1550 = -(copt226 * copt825);
  Real copt1551 = 2 * copt50 * copt830;
  Real copt1552 = copt1549 + copt1550 + copt1551 + copt882;
  Real copt1553 = copt1552 * copt527;
  Real copt1554 = -(copt226 * copt530 * copt789);
  Real copt1555 = 2 * copt50 * copt535 * copt789;
  Real copt1556 = -(copt226 * copt535 * copt789);
  Real copt1557 = -2 * copt50 * copt541 * copt802;
  Real copt1558 = 2 * copt226 * copt541 * copt802;
  Real copt1559 = -(copt226 * copt544 * copt802);
  Real copt1560 = 2 * copt50 * copt548 * copt802;
  Real copt1561 = -(copt226 * copt548 * copt802);
  Real copt1562 = -(copt530 * copt830);
  Real copt1563 = -(copt535 * copt789);
  Real copt1564 = -(copt544 * copt838);
  Real copt1565 = -(copt548 * copt802);
  Real copt1566 = copt1562 + copt1563 + copt1564 + copt1565 + copt763 + copt773;
  Real copt1567 = copt1566 * copt45;
  Real copt1568 = copt1536 + copt1537 + copt1538 + copt1539 + copt1540 +
                  copt1541 + copt1542 + copt1543 + copt1544 + copt1545 +
                  copt1546 + copt1547 + copt1548 + copt1553 + copt1554 +
                  copt1555 + copt1556 + copt1557 + copt1558 + copt1559 +
                  copt1560 + copt1561 + copt1567;
  Real copt1569 = copt1568 * copt755;
  Real copt1571 = copt1570 * copt747 * copt870;
  Real copt1572 = copt1569 + copt1571;
  Real copt1573 = -(copt1252 * copt1572 * copt875 * copt899);
  Real copt1574 = copt1535 + copt1573;
  Real copt1578 = copt646 * copt933;
  Real copt1579 = copt627 * copt933;
  Real copt1580 = -(copt763 * copt922);
  Real copt1581 = -(copt773 * copt922);
  Real copt1583 = copt226 * copt535 * copt936;
  Real copt1585 = -2 * copt535 * copt922;
  Real copt1586 = copt45 * copt938;
  Real copt1587 = copt1584 + copt1585 + copt1586 + copt984;
  Real copt1588 = -(copt1587 * copt527);
  Real copt1590 = copt226 * copt548 * copt951;
  Real copt1592 = -2 * copt548 * copt922;
  Real copt1593 = copt45 * copt953;
  Real copt1594 = copt1011 + copt1591 + copt1592 + copt1593;
  Real copt1595 = -(copt1594 * copt541);
  Real copt1596 = copt1576 + copt1577 + copt1578 + copt1579 + copt1580 +
                  copt1581 + copt1582 + copt1583 + copt1588 + copt1589 +
                  copt1590 + copt1595;
  Real copt1597 = -(copt1021 * copt1042 * copt1320 * copt1596 * copt913);
  Real copt1598 = copt541 * copt938;
  Real copt1599 = -(copt535 * copt951);
  Real copt1600 = copt1038 * copt527;
  Real copt1601 = copt1468 + copt1598 + copt1599 + copt1600;
  Real copt1602 = copt1016 * copt1021 * copt1320 * copt1601 * copt913;
  Real copt1603 = copt1597 + copt1602;
  Real copt1608 = copt541 * copt720;
  Real copt1609 = -(copt45 * copt636);
  Real copt1610 = copt1607 + copt1608 + copt1609 + copt663 + copt666;
  Real copt1611 = copt1610 * copt710;
  Real copt1614 = copt1612 + copt1613;
  Real copt1615 = copt1614 * copt740;
  Real copt1616 = copt1611 + copt1615;
  Real copt1617 = -(copt1212 * copt1616 * copt595 * copt705);
  Real copt1618 = 2 * copt530 * copt596;
  Real copt1619 = -2 * copt226 * copt45 * copt530;
  Real copt1620 = -(copt535 * copt596);
  Real copt1621 = copt45 * copt50 * copt535;
  Real copt1622 = -2 * copt45 * copt530 * copt607;
  Real copt1623 = 2 * copt226 * copt530 * copt607;
  Real copt1624 = copt45 * copt535 * copt607;
  Real copt1625 = -(copt50 * copt535 * copt607);
  Real copt1626 = copt1613 + copt722 + copt749;
  Real copt1627 = copt1626 * copt627;
  Real copt1628 = -(copt596 * copt616);
  Real copt1629 = copt45 * copt50 * copt616;
  Real copt1630 = copt226 * copt45 * copt616;
  Real copt1631 = -(copt226 * copt50 * copt616);
  Real copt1632 = -(copt544 * copt548 * copt616);
  Real copt1633 = -(copt535 * copt544 * copt636);
  Real copt1634 = 2 * copt530 * copt548 * copt636;
  Real copt1638 =
      copt1201 + copt1465 + copt1481 + copt1635 + copt1636 + copt1637;
  Real copt1639 = copt1638 * copt541;
  Real copt1648 = -2 * copt548 * copt636;
  Real copt1649 = copt541 * copt669;
  Real copt1650 = copt1640 + copt1641 + copt1642 + copt1643 + copt1646 +
                  copt1647 + copt1648 + copt1649;
  Real copt1651 = copt1650 * copt527;
  Real copt1652 = copt1618 + copt1619 + copt1620 + copt1621 + copt1622 +
                  copt1623 + copt1624 + copt1625 + copt1627 + copt1628 +
                  copt1629 + copt1630 + copt1631 + copt1632 + copt1633 +
                  copt1634 + copt1639 + copt1651;
  Real copt1653 = -(copt1652 * copt595);
  Real copt1654 = copt1214 * copt589 * copt705;
  Real copt1655 = copt1653 + copt1654;
  Real copt1656 = -(copt1212 * copt1655 * copt710 * copt740);
  Real copt1657 = copt1617 + copt1656;
  Real copt1659 = -(copt548 * copt776);
  Real copt1660 = copt541 * copt883;
  Real copt1661 = -(copt45 * copt802);
  Real copt1663 = copt1607 + copt1659 + copt1660 + copt1661 + copt1662;
  Real copt1664 = copt1663 * copt875;
  Real copt1665 = copt1373 + copt1613;
  Real copt1666 = copt1665 * copt899;
  Real copt1667 = copt1664 + copt1666;
  Real copt1668 = copt1252 * copt1667 * copt755 * copt870;
  Real copt1669 = -2 * copt530 * copt757;
  Real copt1670 = 2 * copt226 * copt50 * copt535;
  Real copt1671 = 2 * copt530 * copt541 * copt548;
  Real copt1672 = -(copt535 * copt541 * copt548);
  Real copt1673 = 2 * copt535 * copt544 * copt548;
  Real copt1674 = -2 * copt530 * copt773;
  Real copt1675 = 2 * copt226 * copt530 * copt776;
  Real copt1676 = -(copt50 * copt535 * copt776);
  Real copt1677 = -(copt226 * copt535 * copt776);
  Real copt1678 = copt541 * copt544 * copt789;
  Real copt1680 = copt757 * copt789;
  Real copt1681 = -(copt541 * copt548 * copt789);
  Real copt1683 = copt773 * copt789;
  Real copt1684 = 2 * copt530 * copt821;
  Real copt1685 = 2 * copt535 * copt776;
  Real copt1686 = -(copt50 * copt830);
  Real copt1687 = -(copt226 * copt856);
  Real copt1688 = copt1684 + copt1685 + copt1686 + copt1687;
  Real copt1689 = copt1688 * copt45;
  Real copt1690 = -(copt50 * copt821);
  Real copt1691 = copt1690 + copt757 + copt836 + copt839;
  Real copt1692 = copt1691 * copt527;
  Real copt1693 = -2 * copt530 * copt541 * copt802;
  Real copt1694 = 2 * copt535 * copt541 * copt802;
  Real copt1695 = 2 * copt530 * copt548 * copt802;
  Real copt1696 = -(copt535 * copt548 * copt802);
  Real copt1697 = copt1379 + copt1669 + copt1670 + copt1671 + copt1672 +
                  copt1673 + copt1674 + copt1675 + copt1676 + copt1677 +
                  copt1678 + copt1679 + copt1680 + copt1681 + copt1682 +
                  copt1683 + copt1689 + copt1692 + copt1693 + copt1694 +
                  copt1695 + copt1696 + copt842;
  Real copt1698 = copt1697 * copt755;
  Real copt1699 = copt1570 * copt750 * copt870;
  Real copt1700 = copt1698 + copt1699;
  Real copt1701 = -(copt1252 * copt1700 * copt875 * copt899);
  Real copt1702 = copt1668 + copt1701;
  Real copt1706 = -(copt45 * copt535 * copt922);
  Real copt1707 = copt627 * copt938;
  Real copt1708 = -(copt596 * copt936);
  Real copt1709 = 2 * copt226 * copt45 * copt936;
  Real copt1711 = copt910 * copt953;
  Real copt1712 = copt1710 + copt1711 + copt931 + copt935;
  Real copt1713 = -(copt1712 * copt527);
  Real copt1716 = copt1268 + copt1714 + copt1715;
  Real copt1717 = -(copt1716 * copt541);
  Real copt1718 = copt1704 + copt1705 + copt1706 + copt1707 + copt1708 +
                  copt1709 + copt1713 + copt1717 + copt973 + copt976 + copt979 +
                  copt990;
  Real copt1719 = -(copt1021 * copt1042 * copt1320 * copt1718 * copt913);
  Real copt1720 = -(copt548 * copt922);
  Real copt1721 = copt1029 * copt541;
  Real copt1722 = -(copt45 * copt951);
  Real copt1723 = copt1011 + copt1607 + copt1720 + copt1721 + copt1722;
  Real copt1724 = copt1016 * copt1021 * copt1320 * copt1723 * copt913;
  Real copt1725 = copt1719 + copt1724;
  Real copt1730 = copt527 * copt733;
  Real copt1731 = copt45 * copt616;
  Real copt1732 = copt1505 + copt1729 + copt1730 + copt1731 + copt688;
  Real copt1733 = copt1732 * copt710;
  Real copt1736 = copt1734 + copt1735;
  Real copt1737 = copt1736 * copt740;
  Real copt1738 = copt1733 + copt1737;
  Real copt1739 = -(copt1212 * copt1738 * copt595 * copt705);
  Real copt1740 = 2 * copt544 * copt596;
  Real copt1741 = -2 * copt226 * copt45 * copt544;
  Real copt1742 = -(copt548 * copt596);
  Real copt1743 = copt45 * copt50 * copt548;
  Real copt1744 = -2 * copt45 * copt544 * copt607;
  Real copt1745 = 2 * copt226 * copt544 * copt607;
  Real copt1746 = copt45 * copt548 * copt607;
  Real copt1747 = -(copt50 * copt548 * copt607);
  Real copt1748 = 2 * copt535 * copt544 * copt616;
  Real copt1749 = -(copt530 * copt548 * copt616);
  Real copt1751 = copt50 * copt629;
  Real copt1753 = -2 * copt535 * copt616;
  Real copt1754 =
      copt1643 + copt1646 + copt1750 + copt1751 + copt1752 + copt1753;
  Real copt1755 = copt1754 * copt541;
  Real copt1756 = copt1198 + copt1735 + copt735;
  Real copt1757 = copt1756 * copt646;
  Real copt1758 = -(copt596 * copt636);
  Real copt1759 = copt45 * copt50 * copt636;
  Real copt1760 = copt226 * copt45 * copt636;
  Real copt1761 = -(copt226 * copt50 * copt636);
  Real copt1762 = -(copt530 * copt535 * copt636);
  Real copt1765 = copt541 * copt690;
  Real copt1767 = copt1201 + copt1255 + copt1481 + copt1763 + copt1764 +
                  copt1765 + copt1766;
  Real copt1768 = copt1767 * copt527;
  Real copt1769 = copt1740 + copt1741 + copt1742 + copt1743 + copt1744 +
                  copt1745 + copt1746 + copt1747 + copt1748 + copt1749 +
                  copt1755 + copt1757 + copt1758 + copt1759 + copt1760 +
                  copt1761 + copt1762 + copt1768;
  Real copt1770 = -(copt1769 * copt595);
  Real copt1771 = copt1214 * copt592 * copt705;
  Real copt1772 = copt1770 + copt1771;
  Real copt1773 = -(copt1212 * copt1772 * copt710 * copt740);
  Real copt1774 = copt1739 + copt1773;
  Real copt1776 = copt527 * copt821;
  Real copt1777 = copt45 * copt789;
  Real copt1778 = -(copt226 * copt789);
  Real copt1779 = copt1729 + copt1776 + copt1777 + copt1778 + copt823;
  Real copt1780 = copt1779 * copt875;
  Real copt1781 = copt1449 + copt1735;
  Real copt1782 = copt1781 * copt899;
  Real copt1783 = copt1780 + copt1782;
  Real copt1784 = copt1252 * copt1783 * copt755 * copt870;
  Real copt1786 = copt541 * copt757;
  Real copt1787 = -2 * copt544 * copt757;
  Real copt1789 = copt541 * copt763;
  Real copt1790 = -2 * copt544 * copt763;
  Real copt1791 = 2 * copt226 * copt50 * copt548;
  Real copt1792 = 2 * copt530 * copt535 * copt548;
  Real copt1793 = copt50 * copt541 * copt776;
  Real copt1794 = -(copt226 * copt541 * copt776);
  Real copt1795 = 2 * copt226 * copt544 * copt776;
  Real copt1796 = -(copt226 * copt548 * copt776);
  Real copt1797 = copt530 * copt541 * copt789;
  Real copt1798 = -(copt535 * copt541 * copt789);
  Real copt1799 = 2 * copt535 * copt544 * copt789;
  Real copt1800 = -(copt535 * copt548 * copt789);
  Real copt1802 = copt757 * copt802;
  Real copt1804 = copt763 * copt802;
  Real copt1805 = 2 * copt535 * copt544;
  Real copt1806 = -(copt535 * copt548);
  Real copt1807 = -2 * copt544 * copt789;
  Real copt1808 = 2 * copt548 * copt789;
  Real copt1809 = -(copt530 * copt838);
  Real copt1810 =
      copt1527 + copt1805 + copt1806 + copt1807 + copt1808 + copt1809;
  Real copt1811 = copt1810 * copt527;
  Real copt1812 = 2 * copt544 * copt821;
  Real copt1813 = 2 * copt548 * copt776;
  Real copt1814 = -(copt50 * copt838);
  Real copt1815 = -(copt226 * copt864);
  Real copt1816 = copt1812 + copt1813 + copt1814 + copt1815;
  Real copt1817 = copt1816 * copt45;
  Real copt1818 = copt1431 + copt1435 + copt1785 + copt1786 + copt1787 +
                  copt1788 + copt1789 + copt1790 + copt1791 + copt1792 +
                  copt1793 + copt1794 + copt1795 + copt1796 + copt1797 +
                  copt1798 + copt1799 + copt1800 + copt1801 + copt1802 +
                  copt1803 + copt1804 + copt1811 + copt1817;
  Real copt1819 = copt1818 * copt755;
  Real copt1820 = copt1570 * copt752 * copt870;
  Real copt1821 = copt1819 + copt1820;
  Real copt1822 = -(copt1252 * copt1821 * copt875 * copt899);
  Real copt1823 = copt1784 + copt1822;
  Real copt1827 = -(copt45 * copt548 * copt922);
  Real copt1830 = copt1710 + copt1828 + copt1829 + copt931 + copt935;
  Real copt1831 = -(copt1830 * copt541);
  Real copt1832 = copt646 * copt953;
  Real copt1833 = -(copt596 * copt951);
  Real copt1834 = 2 * copt226 * copt45 * copt951;
  Real copt1836 = -(copt541 * copt936);
  Real copt1838 = copt1468 + copt1714 + copt1835 + copt1836 + copt1837;
  Real copt1839 = -(copt1838 * copt527);
  Real copt1840 = copt1004 + copt1006 + copt1825 + copt1826 + copt1827 +
                  copt1831 + copt1832 + copt1833 + copt1834 + copt1839 +
                  copt996 + copt998;
  Real copt1841 = -(copt1021 * copt1042 * copt1320 * copt1840 * copt913);
  Real copt1842 = copt527 * copt933;
  Real copt1843 = copt45 * copt936;
  Real copt1844 = -(copt226 * copt936);
  Real copt1845 = copt1729 + copt1842 + copt1843 + copt1844 + copt982;
  Real copt1846 = copt1016 * copt1021 * copt1320 * copt1845 * copt913;
  Real copt1847 = copt1841 + copt1846;
  Real copt1853 = copt597 * copt607;
  Real copt1854 = copt599 * copt607;
  Real copt1856 = copt1855 * copt646;
  Real copt1857 = copt1855 * copt627;
  Real copt1858 = -(copt50 * copt530 * copt616);
  Real copt1860 = -2 * copt530 * copt607;
  Real copt1862 = copt1861 * copt45;
  Real copt1864 = copt1859 + copt1860 + copt1862 + copt1863;
  Real copt1865 = copt1864 * copt527;
  Real copt1866 = -(copt50 * copt544 * copt636);
  Real copt1867 = -2 * copt544 * copt607;
  Real copt1869 = copt1868 * copt45;
  Real copt1870 = copt544 + copt636;
  Real copt1871 = copt1870 * copt50;
  Real copt1872 = copt1867 + copt1869 + copt1871;
  Real copt1873 = copt1872 * copt541;
  Real copt1874 = copt1498 + copt1510 + copt1851 + copt1852 + copt1853 +
                  copt1854 + copt1856 + copt1857 + copt1858 + copt1865 +
                  copt1866 + copt1873;
  Real copt1875 = copt1212 * copt1874 * copt595 * copt710 * copt740;
  Real copt1876 = -(copt544 * copt616);
  Real copt1878 = copt1877 * copt541;
  Real copt1879 = copt1868 * copt527;
  Real copt1880 = copt1766 + copt1876 + copt1878 + copt1879;
  Real copt1881 = -(copt1212 * copt1880 * copt595 * copt705 * copt710);
  Real copt1882 = copt1875 + copt1881;
  Real copt1884 = -(copt544 * copt789);
  Real copt1885 = copt588 + copt789;
  Real copt1886 = copt1885 * copt541;
  Real copt1887 = copt544 + copt837;
  Real copt1888 = copt1887 * copt527;
  Real copt1889 = copt530 * copt802;
  Real copt1890 = copt1884 + copt1886 + copt1888 + copt1889;
  Real copt1891 = copt1890 * copt875;
  Real copt1893 = copt1644 + copt1892;
  Real copt1894 = copt1893 * copt899;
  Real copt1895 = copt1891 + copt1894;
  Real copt1896 = copt1252 * copt1895 * copt755 * copt870;
  Real copt1897 = -(copt50 * copt541 * copt544);
  Real copt1898 = -2 * copt226 * copt597;
  Real copt1899 = 2 * copt226 * copt541 * copt544;
  Real copt1900 = -2 * copt226 * copt599;
  Real copt1901 = 2 * copt50 * copt530 * copt535;
  Real copt1903 = 2 * copt50 * copt544 * copt548;
  Real copt1904 = copt597 * copt776;
  Real copt1905 = -(copt541 * copt544 * copt776);
  Real copt1906 = copt599 * copt776;
  Real copt1907 = copt541 * copt548 * copt776;
  Real copt1908 = -(copt50 * copt530 * copt789);
  Real copt1909 = 2 * copt226 * copt530 * copt789;
  Real copt1910 = copt1892 + copt820;
  Real copt1911 = copt1910 * copt530;
  Real copt1912 = copt530 + copt535 + copt824;
  Real copt1913 = -(copt1912 * copt50);
  Real copt1914 = -2 * copt226 * copt789;
  Real copt1915 = copt1911 + copt1913 + copt1914 + copt823;
  Real copt1916 = copt1915 * copt527;
  Real copt1917 = 2 * copt50 * copt541 * copt802;
  Real copt1918 = -(copt50 * copt544 * copt802);
  Real copt1919 = -2 * copt226 * copt541 * copt802;
  Real copt1920 = 2 * copt226 * copt544 * copt802;
  Real copt1921 = copt535 * copt789;
  Real copt1922 = -(copt530 * copt856);
  Real copt1924 = -(copt544 * copt864);
  Real copt1925 = copt1921 + copt1922 + copt1923 + copt1924 + copt597 + copt599;
  Real copt1926 = copt1925 * copt45;
  Real copt1927 = copt1544 + copt1547 + copt1897 + copt1898 + copt1899 +
                  copt1900 + copt1901 + copt1902 + copt1903 + copt1904 +
                  copt1905 + copt1906 + copt1907 + copt1908 + copt1909 +
                  copt1916 + copt1917 + copt1918 + copt1919 + copt1920 +
                  copt1926 + copt852 + copt860;
  Real copt1928 = copt1927 * copt755;
  Real copt1929 = -(copt1570 * copt747 * copt870);
  Real copt1930 = copt1928 + copt1929;
  Real copt1931 = -(copt1252 * copt1930 * copt875 * copt899);
  Real copt1932 = copt1896 + copt1931;
  Real copt1934 = copt588 + copt936;
  Real copt1935 = copt1934 * copt541;
  Real copt1936 = copt544 + copt952;
  Real copt1937 = copt1936 * copt527;
  Real copt1939 = copt1467 + copt1935 + copt1937 + copt1938;
  Real copt1940 = copt1021 * copt1939;
  Real copt1941 = copt1485 + copt1892;
  Real copt1942 = copt1042 * copt1941;
  Real copt1943 = copt1940 + copt1942;
  Real copt1944 = copt1016 * copt1320 * copt1943 * copt913;
  Real copt1947 = copt530 * copt535 * copt922;
  Real copt1948 = copt544 * copt548 * copt922;
  Real copt1950 = copt1949 * copt646;
  Real copt1951 = copt1949 * copt627;
  Real copt1952 = 2 * copt45 * copt530 * copt936;
  Real copt1953 = -2 * copt226 * copt530 * copt936;
  Real copt1954 = copt50 * copt535 * copt936;
  Real copt1957 = copt530 * copt922;
  Real copt1959 = -2 * copt226 * copt936;
  Real copt1961 = copt1960 * copt45;
  Real copt1962 =
      copt1955 + copt1956 + copt1957 + copt1958 + copt1959 + copt1961 + copt982;
  Real copt1963 = -(copt1962 * copt527);
  Real copt1964 = 2 * copt45 * copt544 * copt951;
  Real copt1965 = -2 * copt226 * copt544 * copt951;
  Real copt1966 = copt50 * copt548 * copt951;
  Real copt1968 = copt1892 + copt932;
  Real copt1969 = -(copt1968 * copt544);
  Real copt1970 = copt50 * copt951;
  Real copt1971 = -2 * copt226 * copt951;
  Real copt1973 = copt1972 * copt45;
  Real copt1974 =
      copt1009 + copt1967 + copt1969 + copt1970 + copt1971 + copt1973;
  Real copt1975 = -(copt1974 * copt541);
  Real copt1976 = copt1582 + copt1589 + copt1945 + copt1946 + copt1947 +
                  copt1948 + copt1950 + copt1951 + copt1952 + copt1953 +
                  copt1954 + copt1963 + copt1964 + copt1965 + copt1966 +
                  copt1975;
  Real copt1977 = copt1976 * copt913;
  Real copt1978 = -(copt1016 * copt1322 * copt906);
  Real copt1979 = copt1977 + copt1978;
  Real copt1980 = -(copt1021 * copt1042 * copt1320 * copt1979);
  Real copt1981 = copt1944 + copt1980;
  Real copt1987 = copt45 * copt530 * copt607;
  Real copt1988 = -(copt50 * copt530 * copt607);
  Real copt1989 = copt596 * copt616;
  Real copt1990 = -2 * copt45 * copt50 * copt616;
  Real copt1991 = copt616 * copt623;
  Real copt1992 = copt599 * copt616;
  Real copt1993 = copt1877 * copt627;
  Real copt1994 = -(copt530 * copt544 * copt636);
  Real copt1996 = copt1764 + copt1766 + copt1995;
  Real copt1997 = copt1996 * copt541;
  Real copt2002 = copt1868 * copt541;
  Real copt2003 =
      copt1642 + copt1647 + copt1998 + copt1999 + copt2001 + copt2002;
  Real copt2004 = copt2003 * copt527;
  Real copt2005 = copt1985 + copt1986 + copt1987 + copt1988 + copt1989 +
                  copt1990 + copt1991 + copt1992 + copt1993 + copt1994 +
                  copt1997 + copt2004;
  Real copt2006 = copt1212 * copt2005 * copt595 * copt710 * copt740;
  Real copt2008 = copt2000 * copt541;
  Real copt2009 = copt544 * copt607;
  Real copt2010 = copt45 * copt636;
  Real copt2011 = -(copt50 * copt636);
  Real copt2012 = copt2007 + copt2008 + copt2009 + copt2010 + copt2011;
  Real copt2013 = -(copt1212 * copt2012 * copt595 * copt705 * copt710);
  Real copt2014 = copt2006 + copt2013;
  Real copt2016 = copt50 + copt820;
  Real copt2017 = copt2016 * copt541;
  Real copt2018 = copt544 * copt776;
  Real copt2019 = copt45 * copt802;
  Real copt2021 = copt2007 + copt2017 + copt2018 + copt2019 + copt2020;
  Real copt2022 = copt2021 * copt875;
  Real copt2024 = copt2023 + copt689;
  Real copt2025 = copt2024 * copt899;
  Real copt2026 = copt2022 + copt2025;
  Real copt2027 = copt1252 * copt2026 * copt755 * copt870;
  Real copt2028 = -(copt530 * copt541 * copt544);
  Real copt2029 = 2 * copt226 * copt50 * copt530;
  Real copt2030 = -2 * copt535 * copt623;
  Real copt2031 = 2 * copt535 * copt541 * copt544;
  Real copt2032 = -2 * copt535 * copt599;
  Real copt2034 = 2 * copt530 * copt544 * copt548;
  Real copt2035 = -(copt50 * copt530 * copt776);
  Real copt2036 = -(copt226 * copt530 * copt776);
  Real copt2037 = 2 * copt50 * copt535 * copt776;
  Real copt2038 = copt623 * copt789;
  Real copt2039 = -(copt541 * copt544 * copt789);
  Real copt2040 = copt599 * copt789;
  Real copt2041 = copt541 * copt548 * copt789;
  Real copt2042 = 2 * copt50 * copt535;
  Real copt2045 = -(copt2044 * copt530);
  Real copt2046 = -(copt50 * copt789);
  Real copt2047 = copt2042 + copt2045 + copt2046 + copt854 + copt885;
  Real copt2048 = copt2047 * copt45;
  Real copt2049 = 2 * copt530 * copt541 * copt802;
  Real copt2050 = -(copt530 * copt544 * copt802);
  Real copt2051 = -2 * copt535 * copt541 * copt802;
  Real copt2052 = 2 * copt535 * copt544 * copt802;
  Real copt2053 = -(copt530 * copt548 * copt802);
  Real copt2054 = -(copt544 * copt548);
  Real copt2055 = copt226 * copt776;
  Real copt2056 = copt226 + copt776;
  Real copt2057 = -(copt2056 * copt50);
  Real copt2058 = -(copt544 * copt802);
  Real copt2059 =
      copt1923 + copt2054 + copt2055 + copt2057 + copt2058 + copt599 + copt623;
  Real copt2060 = copt2059 * copt527;
  Real copt2061 = copt1679 + copt1682 + copt2028 + copt2029 + copt2030 +
                  copt2031 + copt2032 + copt2033 + copt2034 + copt2035 +
                  copt2036 + copt2037 + copt2038 + copt2039 + copt2040 +
                  copt2041 + copt2048 + copt2049 + copt2050 + copt2051 +
                  copt2052 + copt2053 + copt2060;
  Real copt2062 = copt2061 * copt755;
  Real copt2063 = -(copt1570 * copt750 * copt870);
  Real copt2064 = copt2062 + copt2063;
  Real copt2065 = -(copt1252 * copt2064 * copt875 * copt899);
  Real copt2066 = copt2027 + copt2065;
  Real copt2068 = copt50 + copt932;
  Real copt2069 = copt2068 * copt541;
  Real copt2070 = copt544 * copt922;
  Real copt2071 = copt45 * copt951;
  Real copt2072 = -(copt50 * copt951);
  Real copt2073 = copt2007 + copt2069 + copt2070 + copt2071 + copt2072;
  Real copt2074 = copt1021 * copt2073;
  Real copt2075 = copt1612 + copt2023;
  Real copt2076 = copt1042 * copt2075;
  Real copt2077 = copt2074 + copt2076;
  Real copt2078 = copt1016 * copt1320 * copt2077 * copt913;
  Real copt2079 = copt530 * copt596;
  Real copt2080 = -(copt226 * copt45 * copt530);
  Real copt2081 = -2 * copt535 * copt596;
  Real copt2082 = 2 * copt45 * copt50 * copt535;
  Real copt2083 = -(copt45 * copt530 * copt922);
  Real copt2084 = 2 * copt45 * copt535 * copt922;
  Real copt2085 = copt596 * copt936;
  Real copt2086 = -(copt45 * copt50 * copt936);
  Real copt2087 = -(copt226 * copt45 * copt936);
  Real copt2088 = copt1960 * copt627;
  Real copt2089 = copt530 * copt548 * copt951;
  Real copt2090 = copt2023 + copt937;
  Real copt2091 = -(copt2090 * copt544);
  Real copt2092 = copt1255 + copt1468 + copt1837 + copt1938 + copt2091;
  Real copt2093 = -(copt2092 * copt541);
  Real copt2094 = copt541 * copt544;
  Real copt2097 = copt541 * copt951;
  Real copt2098 = -2 * copt544 * copt951;
  Real copt2099 = copt548 * copt951;
  Real copt2100 = copt1020 + copt1640 + copt1641 + copt2094 + copt2095 +
                  copt2096 + copt2097 + copt2098 + copt2099 + copt935;
  Real copt2101 = -(copt2100 * copt527);
  Real copt2102 = copt2079 + copt2080 + copt2081 + copt2082 + copt2083 +
                  copt2084 + copt2085 + copt2086 + copt2087 + copt2088 +
                  copt2089 + copt2093 + copt2101 + copt971 + copt972 + copt975 +
                  copt978 + copt989;
  Real copt2103 = copt2102 * copt913;
  Real copt2104 = -(copt1016 * copt1322 * copt908);
  Real copt2105 = copt2103 + copt2104;
  Real copt2106 = -(copt1021 * copt1042 * copt1320 * copt2105);
  Real copt2107 = copt2078 + copt2106;
  Real copt2113 = copt45 * copt544 * copt607;
  Real copt2114 = -(copt50 * copt544 * copt607);
  Real copt2115 = -(copt530 * copt544 * copt616);
  Real copt2117 = copt1642 + copt1752 + copt1998 + copt2001 + copt2116;
  Real copt2118 = copt2117 * copt541;
  Real copt2119 = copt596 * copt636;
  Real copt2120 = -2 * copt45 * copt50 * copt636;
  Real copt2121 = copt623 * copt636;
  Real copt2122 = copt597 * copt636;
  Real copt2123 = copt591 + copt636;
  Real copt2124 = copt2123 * copt646;
  Real copt2125 = copt1861 * copt541;
  Real copt2126 = copt1636 + copt1637 + copt1995 + copt2125;
  Real copt2127 = copt2126 * copt527;
  Real copt2128 = copt2111 + copt2112 + copt2113 + copt2114 + copt2115 +
                  copt2118 + copt2119 + copt2120 + copt2121 + copt2122 +
                  copt2124 + copt2127;
  Real copt2129 = copt1212 * copt2128 * copt595 * copt710 * copt740;
  Real copt2131 = -(copt530 * copt607);
  Real copt2132 = copt1855 * copt527;
  Real copt2133 = -(copt45 * copt616);
  Real copt2134 = copt1863 + copt2130 + copt2131 + copt2132 + copt2133;
  Real copt2135 = -(copt1212 * copt2134 * copt595 * copt705 * copt710);
  Real copt2136 = copt2129 + copt2135;
  Real copt2138 = -(copt530 * copt776);
  Real copt2139 = copt585 + copt776;
  Real copt2140 = copt2139 * copt527;
  Real copt2141 = -(copt45 * copt789);
  Real copt2142 = copt50 * copt789;
  Real copt2143 = copt2130 + copt2138 + copt2140 + copt2141 + copt2142;
  Real copt2144 = copt2143 * copt875;
  Real copt2146 = copt2145 + copt668;
  Real copt2147 = copt2146 * copt899;
  Real copt2148 = copt2144 + copt2147;
  Real copt2149 = copt1252 * copt2148 * copt755 * copt870;
  Real copt2150 = copt541 * copt623;
  Real copt2151 = copt541 * copt597;
  Real copt2152 = 2 * copt226 * copt50 * copt544;
  Real copt2153 = 2 * copt530 * copt535 * copt544;
  Real copt2154 = -2 * copt548 * copt623;
  Real copt2155 = -2 * copt548 * copt597;
  Real copt2156 = -(copt50 * copt541 * copt776);
  Real copt2157 = -(copt50 * copt544 * copt776);
  Real copt2158 = copt226 * copt541 * copt776;
  Real copt2159 = 2 * copt50 * copt548 * copt776;
  Real copt2160 = -(copt530 * copt541 * copt789);
  Real copt2161 = -(copt530 * copt544 * copt789);
  Real copt2162 = copt535 * copt541 * copt789;
  Real copt2163 = 2 * copt530 * copt548 * copt789;
  Real copt2164 = copt623 * copt802;
  Real copt2165 = copt597 * copt802;
  Real copt2166 = 2 * copt50 * copt548;
  Real copt2167 = -(copt2044 * copt544);
  Real copt2168 = copt1662 + copt2020 + copt2166 + copt2167 + copt862;
  Real copt2169 = copt2168 * copt45;
  Real copt2170 = 2 * copt544 * copt789;
  Real copt2171 = -2 * copt548 * copt789;
  Real copt2172 = copt2145 + copt591 + copt837;
  Real copt2173 = copt2172 * copt530;
  Real copt2174 = copt1254 + copt1259 + copt2170 + copt2171 + copt2173;
  Real copt2175 = copt2174 * copt527;
  Real copt2176 = copt1430 + copt1434 + copt1785 + copt1788 + copt1801 +
                  copt1803 + copt2150 + copt2151 + copt2152 + copt2153 +
                  copt2154 + copt2155 + copt2156 + copt2157 + copt2158 +
                  copt2159 + copt2160 + copt2161 + copt2162 + copt2163 +
                  copt2164 + copt2165 + copt2169 + copt2175;
  Real copt2177 = copt2176 * copt755;
  Real copt2178 = -(copt1570 * copt752 * copt870);
  Real copt2179 = copt2177 + copt2178;
  Real copt2180 = -(copt1252 * copt2179 * copt875 * copt899);
  Real copt2181 = copt2149 + copt2180;
  Real copt2183 = -(copt530 * copt922);
  Real copt2184 = copt585 + copt922;
  Real copt2185 = copt2184 * copt527;
  Real copt2186 = -(copt45 * copt936);
  Real copt2187 = copt1958 + copt2130 + copt2183 + copt2185 + copt2186;
  Real copt2188 = copt1021 * copt2187;
  Real copt2189 = copt1734 + copt2145;
  Real copt2190 = copt1042 * copt2189;
  Real copt2191 = copt2188 + copt2190;
  Real copt2192 = copt1016 * copt1320 * copt2191 * copt913;
  Real copt2193 = copt544 * copt596;
  Real copt2194 = -(copt226 * copt45 * copt544);
  Real copt2195 = -2 * copt548 * copt596;
  Real copt2196 = 2 * copt45 * copt50 * copt548;
  Real copt2197 = -(copt45 * copt544 * copt922);
  Real copt2198 = copt226 * copt544 * copt922;
  Real copt2199 = 2 * copt45 * copt548 * copt922;
  Real copt2200 = copt535 * copt544 * copt936;
  Real copt2201 = -2 * copt530 * copt936;
  Real copt2202 =
      copt1640 + copt1750 + copt1829 + copt2095 + copt2096 + copt2201 + copt935;
  Real copt2203 = -(copt2202 * copt541);
  Real copt2204 = copt596 * copt951;
  Real copt2205 = -(copt45 * copt50 * copt951);
  Real copt2206 = -(copt226 * copt45 * copt951);
  Real copt2207 = copt1972 * copt646;
  Real copt2208 = -2 * copt535 * copt541;
  Real copt2209 = copt530 * copt910;
  Real copt2210 = copt541 * copt936;
  Real copt2211 = copt544 * copt936;
  Real copt2212 = -(copt530 * copt953);
  Real copt2213 = copt1268 + copt1465 + copt1715 + copt2208 + copt2209 +
                  copt2210 + copt2211 + copt2212;
  Real copt2214 = -(copt2213 * copt527);
  Real copt2215 = copt1003 + copt1005 + copt2193 + copt2194 + copt2195 +
                  copt2196 + copt2197 + copt2198 + copt2199 + copt2200 +
                  copt2203 + copt2204 + copt2205 + copt2206 + copt2207 +
                  copt2214 + copt995 + copt997;
  Real copt2216 = copt2215 * copt913;
  Real copt2217 = -(copt1016 * copt1322 * copt910);
  Real copt2218 = copt2216 + copt2217;
  Real copt2219 = -(copt1021 * copt1042 * copt1320 * copt2218);
  Real copt2220 = copt2192 + copt2219;
  Real copt2230 = copt45 * copt750;
  Real copt2231 = copt1859 + copt1955 + copt1956 + copt2230;
  Real copt2232 = copt2231 * copt527;
  Real copt2234 = -2 * copt226 * copt544;
  Real copt2235 = copt45 * copt752;
  Real copt2236 = copt544 + copt548;
  Real copt2237 = copt2236 * copt50;
  Real copt2238 = copt2234 + copt2235 + copt2237;
  Real copt2239 = copt2238 * copt541;
  Real copt2240 = copt1491 + copt1492 + copt1851 + copt1852 + copt2224 +
                  copt2225 + copt2227 + copt2228 + copt2229 + copt2232 +
                  copt2233 + copt2239;
  Real copt2241 = copt1212 * copt2240 * copt595 * copt710 * copt740;
  Real copt2247 = -(copt1212 * copt2246 * copt595 * copt705 * copt710);
  Real copt2248 = copt2241 + copt2247;
  Real copt2250 = copt226 * copt45 * copt530;
  Real copt2252 = -2 * copt45 * copt50 * copt535;
  Real copt2257 = copt1255 + copt1763 + copt1995;
  Real copt2258 = copt2257 * copt541;
  Real copt2260 = copt541 * copt752;
  Real copt2261 =
      copt1640 + copt1641 + copt1998 + copt1999 + copt2259 + copt2260;
  Real copt2262 = copt2261 * copt527;
  Real copt2263 = copt1704 + copt1985 + copt1986 + copt2250 + copt2251 +
                  copt2252 + copt2253 + copt2255 + copt2256 + copt2258 +
                  copt2262 + copt817;
  Real copt2264 = copt1212 * copt2263 * copt595 * copt710 * copt740;
  Real copt2270 = -(copt1212 * copt2269 * copt595 * copt705 * copt710);
  Real copt2271 = copt2264 + copt2270;
  Real copt2273 = copt226 * copt45 * copt544;
  Real copt2274 = copt1640 + copt1750 + copt1998 + copt2116 + copt2259;
  Real copt2275 = copt2274 * copt541;
  Real copt2276 = -2 * copt45 * copt50 * copt548;
  Real copt2278 = copt1465 + copt1635 + copt1995 + copt2242;
  Real copt2279 = copt2278 * copt527;
  Real copt2280 = copt1421 + copt1423 + copt1425 + copt1426 + copt1825 +
                  copt2111 + copt2112 + copt2273 + copt2275 + copt2276 +
                  copt2277 + copt2279;
  Real copt2281 = copt1212 * copt2280 * copt595 * copt710 * copt740;
  Real copt2287 = -(copt1212 * copt2286 * copt595 * copt705 * copt710);
  Real copt2288 = copt2281 + copt2287;
  Real copt2290 = copt50 * copt541 * copt544;
  Real copt2291 = -(copt226 * copt530);
  Real copt2292 = -(copt2254 * copt50);
  Real copt2293 = copt1584 + copt2291 + copt2292;
  Real copt2294 = copt2293 * copt527;
  Real copt2295 = copt226 * copt541 * copt548;
  Real copt2296 = 2 * copt530 * copt535;
  Real copt2299 =
      copt1828 + copt1999 + copt2116 + copt2296 + copt2297 + copt2298;
  Real copt2300 = copt2299 * copt45;
  Real copt2301 = copt1324 + copt1327 + copt1536 + copt1902 + copt2224 +
                  copt2225 + copt2229 + copt2233 + copt2290 + copt2294 +
                  copt2295 + copt2300 + copt846 + copt847;
  Real copt2302 = -(copt1252 * copt2301 * copt755 * copt875 * copt899);
  Real copt2303 = copt1252 * copt2246 * copt755 * copt870 * copt875;
  Real copt2304 = copt2302 + copt2303;
  Real copt2306 = copt530 * copt541 * copt544;
  Real copt2307 = -(copt2226 * copt530);
  Real copt2308 = copt1584 + copt2285 + copt2307;
  Real copt2309 = copt2308 * copt45;
  Real copt2310 = copt535 * copt541 * copt548;
  Real copt2311 = copt530 * copt773;
  Real copt2312 = 2 * copt226 * copt50;
  Real copt2313 =
      copt1998 + copt1999 + copt2297 + copt2298 + copt2312 + copt931;
  Real copt2314 = copt2313 * copt527;
  Real copt2315 = copt1378 + copt1379 + copt1380 + copt2033 + copt2251 +
                  copt2253 + copt2256 + copt2306 + copt2309 + copt2310 +
                  copt2311 + copt2314 + copt817 + copt818;
  Real copt2316 = -(copt1252 * copt2315 * copt755 * copt875 * copt899);
  Real copt2317 = copt1252 * copt2269 * copt755 * copt870 * copt875;
  Real copt2318 = copt2316 + copt2317;
  Real copt2320 = -(copt541 * copt623);
  Real copt2321 = -(copt541 * copt597);
  Real copt2322 = 2 * copt226 * copt50 * copt541;
  Real copt2323 = -(copt541 * copt757);
  Real copt2324 = 2 * copt530 * copt535 * copt541;
  Real copt2325 = -(copt541 * copt763);
  Real copt2326 = -(copt2226 * copt544);
  Real copt2327 = -(copt50 * copt548);
  Real copt2328 = copt1591 + copt2326 + copt2327;
  Real copt2329 = copt2328 * copt45;
  Real copt2330 = copt530 * copt752;
  Real copt2331 = copt1254 + copt1714 + copt2330;
  Real copt2332 = copt2331 * copt527;
  Real copt2333 = copt1421 + copt1422 + copt1423 + copt1424 + copt1425 +
                  copt1426 + copt1427 + copt1428 + copt2320 + copt2321 +
                  copt2322 + copt2323 + copt2324 + copt2325 + copt2329 +
                  copt2332;
  Real copt2334 = -(copt1252 * copt2333 * copt755 * copt875 * copt899);
  Real copt2335 = copt1252 * copt2286 * copt755 * copt870 * copt875;
  Real copt2336 = copt2334 + copt2335;
  Real copt2338 = copt226 * copt530 * copt535;
  Real copt2339 = -(copt50 * copt763);
  Real copt2340 = copt2254 * copt45;
  Real copt2341 = copt1502 + copt1503 + copt1584 + copt2340;
  Real copt2342 = -(copt2341 * copt527);
  Real copt2343 = copt226 * copt544 * copt548;
  Real copt2344 = -(copt50 * copt773);
  Real copt2345 = copt226 * copt544;
  Real copt2346 = -2 * copt50 * copt548;
  Real copt2347 = copt2244 * copt45;
  Real copt2348 = copt1591 + copt2345 + copt2346 + copt2347;
  Real copt2349 = -(copt2348 * copt541);
  Real copt2350 = copt1576 + copt1577 + copt1945 + copt1946 + copt2227 +
                  copt2228 + copt2338 + copt2339 + copt2342 + copt2343 +
                  copt2344 + copt2349;
  Real copt2351 = -(copt1021 * copt1042 * copt1320 * copt2350 * copt913);
  Real copt2352 = copt1016 * copt1021 * copt1320 * copt2246 * copt913;
  Real copt2353 = copt2351 + copt2352;
  Real copt2355 = 2 * copt226 * copt45 * copt530;
  Real copt2356 = -(copt45 * copt50 * copt535);
  Real copt2357 = -(copt530 * copt773);
  Real copt2358 = copt1465 + copt1635 + copt1714;
  Real copt2359 = -(copt2358 * copt541);
  Real copt2360 = -(copt541 * copt544);
  Real copt2362 = copt541 * copt548;
  Real copt2363 =
      copt1640 + copt1641 + copt2298 + copt2360 + copt2361 + copt2362 + copt931;
  Real copt2364 = -(copt2363 * copt527);
  Real copt2365 = copt1704 + copt1705 + copt1985 + copt2255 + copt2355 +
                  copt2356 + copt2357 + copt2359 + copt2364 + copt966 +
                  copt968 + copt970;
  Real copt2366 = -(copt1021 * copt1042 * copt1320 * copt2365 * copt913);
  Real copt2367 = copt1016 * copt1021 * copt1320 * copt2269 * copt913;
  Real copt2368 = copt2366 + copt2367;
  Real copt2370 = 2 * copt226 * copt45 * copt544;
  Real copt2371 = -(copt544 * copt757);
  Real copt2372 = -(copt544 * copt763);
  Real copt2373 = copt1640 + copt1750 + copt1828 + copt2361 + copt931;
  Real copt2374 = -(copt2373 * copt541);
  Real copt2375 = -(copt45 * copt50 * copt548);
  Real copt2376 = -(copt530 * copt910);
  Real copt2377 = copt1714 + copt1763 + copt1835 + copt2376;
  Real copt2378 = -(copt2377 * copt527);
  Real copt2379 = copt1825 + copt1826 + copt2111 + copt2277 + copt2370 +
                  copt2371 + copt2372 + copt2374 + copt2375 + copt2378 +
                  copt993 + copt994;
  Real copt2380 = -(copt1021 * copt1042 * copt1320 * copt2379 * copt913);
  Real copt2381 = copt1016 * copt1021 * copt1320 * copt2286 * copt913;
  Real copt2382 = copt2380 + copt2381;
  out1(0)       = copt554;
  out1(1)       = copt555 * copt570 * copt576;
  out1(2)       = copt575;
  out1(3) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1044 * copt904 * l0 * l1 + copt745 * copt901 * l0 * l2 +
         copt583 * copt742 * l1 * l2 + copt583 * l1 * l2 * thetarest0 +
         copt745 * l0 * l2 * thetarest1 + copt904 * l0 * l1 * thetarest2)) /
      2.;
  out1(4) = -(copt578 * copt579 * copt580 * copt581 *
              (copt1044 * copt1054 * copt903 * l0 * l1 +
               copt1051 * copt744 * copt901 * l0 * l2 +
               copt1048 * copt582 * copt742 * l1 * l2 +
               copt1048 * copt582 * l1 * l2 * thetarest0 +
               copt1051 * copt744 * l0 * l2 * thetarest1 +
               copt1054 * copt903 * l0 * l1 * thetarest2)) /
            2.;
  out1(5) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1044 * copt1065 * l0 * l1 + copt1062 * copt901 * l0 * l2 +
         copt1059 * copt742 * l1 * l2 + copt1059 * l1 * l2 * thetarest0 +
         copt1062 * l0 * l2 * thetarest1 + copt1065 * l0 * l1 * thetarest2)) /
      2.;
  out2(0, 0)  = copt1070 * copt1073 * copt555;
  out2(0, 1)  = copt1070 * copt1077 * copt555;
  out2(0, 2)  = copt1070 * copt1081 * copt555;
  out2(0, 3)  = copt41 * copt525 * copt555;
  out2(0, 4)  = copt41 * copt538 * copt555;
  out2(0, 5)  = copt41 * copt551 * copt555;
  out2(0, 6)  = copt223 * copt525 * copt555;
  out2(0, 7)  = copt223 * copt538 * copt555;
  out2(0, 8)  = copt223 * copt551 * copt555;
  out2(0, 9)  = 0;
  out2(0, 10) = 0;
  out2(0, 11) = 0;
  out2(0, 12) = 0;
  out2(0, 13) = 0;
  out2(0, 14) = 0;
  out2(0, 15) = 0;
  out2(0, 16) = 0;
  out2(0, 17) = 0;
  out2(1, 0) =
      copt1090 * copt1092 *
      (copt1093 * copt553 * copt560 * copt570 +
       (copt1073 * copt1093 + copt1070 * copt1098) * copt553 * copt574 +
       copt1070 * copt525 * copt570 * copt574);
  out2(1, 1) =
      copt1090 * copt1092 *
      (copt1093 * copt553 * copt564 * copt570 +
       (copt1077 * copt1093 + copt1070 * copt1109) * copt553 * copt574 +
       copt1070 * copt538 * copt570 * copt574);
  out2(1, 2) =
      copt1090 * copt1092 *
      (copt1093 * copt553 * copt568 * copt570 +
       (copt1081 * copt1093 + copt1070 * copt1120) * copt553 * copt574 +
       copt1070 * copt551 * copt570 * copt574);
  out2(1, 3) = copt1090 * copt1092 *
               (-(copt553 * copt556 * copt560 * copt570) -
                copt41 * copt525 * copt570 * copt574 +
                copt553 * copt574 *
                    (copt223 * copt382 * copt556 +
                     copt41 * (copt559 - 2 * copt556 * copt586)));
  out2(1, 4) = copt1090 * copt1092 *
               (-(copt553 * copt556 * copt564 * copt570) -
                copt41 * copt538 * copt570 * copt574 +
                copt553 * copt574 *
                    (copt223 * copt536 * copt556 +
                     copt41 * (copt563 - 2 * copt556 * copt589)));
  out2(1, 5) = copt1090 * copt1092 *
               (-(copt553 * copt556 * copt568 * copt570) -
                copt41 * copt551 * copt570 * copt574 +
                copt553 * copt574 *
                    (copt223 * copt549 * copt556 +
                     copt41 * (copt567 - 2 * copt556 * copt592)));
  out2(1, 6) = copt1090 * copt1092 *
               (-(copt553 * copt558 * copt560 * copt570) -
                copt223 * copt525 * copt570 * copt574 +
                copt553 * copt574 *
                    (copt223 * copt556 * copt57 +
                     copt558 * (2 * copt223 * copt382 + copt64)));
  out2(1, 7) = copt1090 * copt1092 *
               (-(copt553 * copt558 * copt564 * copt570) +
                copt553 *
                    (copt223 * copt532 * copt556 +
                     (copt533 + 2 * copt223 * copt536) * copt558) *
                    copt574 -
                copt223 * copt538 * copt570 * copt574);
  out2(1, 8) = copt1090 * copt1092 *
               (-(copt553 * copt558 * copt568 * copt570) +
                copt553 *
                    (copt223 * copt546 * copt556 +
                     (copt547 + 2 * copt223 * copt549) * copt558) *
                    copt574 -
                copt223 * copt551 * copt570 * copt574);
  out2(1, 9)  = 0;
  out2(1, 10) = 0;
  out2(1, 11) = 0;
  out2(1, 12) = 0;
  out2(1, 13) = 0;
  out2(1, 14) = 0;
  out2(1, 15) = 0;
  out2(1, 16) = 0;
  out2(1, 17) = 0;
  out2(2, 0)  = copt1093 * copt1098 * copt576;
  out2(2, 1)  = copt1093 * copt1109 * copt576;
  out2(2, 2)  = copt1093 * copt1120 * copt576;
  out2(2, 3)  = copt556 * copt560 * copt576;
  out2(2, 4)  = copt556 * copt564 * copt576;
  out2(2, 5)  = copt556 * copt568 * copt576;
  out2(2, 6)  = copt558 * copt560 * copt576;
  out2(2, 7)  = copt558 * copt564 * copt576;
  out2(2, 8)  = copt558 * copt568 * copt576;
  out2(2, 9)  = 0;
  out2(2, 10) = 0;
  out2(2, 11) = 0;
  out2(2, 12) = 0;
  out2(2, 13) = 0;
  out2(2, 14) = 0;
  out2(2, 15) = 0;
  out2(2, 16) = 0;
  out2(2, 17) = 0;
  out2(3, 0)  = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1350 * copt904 * l0 * l1 + copt1262 * copt745 * l0 * l2 +
                  copt1244 * copt583 * l1 * l2)) /
               2.;
  out2(3, 1) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1402 * copt904 * l0 * l1 + copt1370 * copt745 * l0 * l2 +
                  copt1366 * copt583 * l1 * l2)) /
               2.;
  out2(3, 2) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1476 * copt904 * l0 * l1 + copt1446 * copt745 * l0 * l2 +
                  copt1419 * copt583 * l1 * l2)) /
               2.;
  out2(3, 3) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1603 * copt904 * l0 * l1 + copt1574 * copt745 * l0 * l2 +
                  copt1523 * copt583 * l1 * l2)) /
               2.;
  out2(3, 4) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1725 * copt904 * l0 * l1 + copt1702 * copt745 * l0 * l2 +
                  copt1657 * copt583 * l1 * l2)) /
               2.;
  out2(3, 5) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1847 * copt904 * l0 * l1 + copt1823 * copt745 * l0 * l2 +
                  copt1774 * copt583 * l1 * l2)) /
               2.;
  out2(3, 6) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1981 * copt904 * l0 * l1 + copt1932 * copt745 * l0 * l2 +
                  copt1882 * copt583 * l1 * l2)) /
               2.;
  out2(3, 7) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt2107 * copt904 * l0 * l1 + copt2066 * copt745 * l0 * l2 +
                  copt2014 * copt583 * l1 * l2)) /
               2.;
  out2(3, 8) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt2220 * copt904 * l0 * l1 + copt2181 * copt745 * l0 * l2 +
                  copt2136 * copt583 * l1 * l2)) /
               2.;
  out2(3, 9)  = -(copt2248 * copt578 * copt579 * copt583) / 2.;
  out2(3, 10) = -(copt2271 * copt578 * copt579 * copt583) / 2.;
  out2(3, 11) = -(copt2288 * copt578 * copt579 * copt583) / 2.;
  out2(3, 12) = -(copt2304 * copt578 * copt580 * copt745) / 2.;
  out2(3, 13) = -(copt2318 * copt578 * copt580 * copt745) / 2.;
  out2(3, 14) = -(copt2336 * copt578 * copt580 * copt745) / 2.;
  out2(3, 15) = -(copt2353 * copt578 * copt581 * copt904) / 2.;
  out2(3, 16) = -(copt2368 * copt578 * copt581 * copt904) / 2.;
  out2(3, 17) = -(copt2382 * copt578 * copt581 * copt904) / 2.;
  out2(4, 0)  = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt1350 * copt903 * l0 * l1 +
                  copt1051 * copt1262 * copt744 * l0 * l2 +
                  copt1048 * copt1244 * copt582 * l1 * l2)) /
               2.;
  out2(4, 1) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt1402 * copt903 * l0 * l1 +
                  copt1051 * copt1370 * copt744 * l0 * l2 +
                  copt1048 * copt1366 * copt582 * l1 * l2)) /
               2.;
  out2(4, 2) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt1476 * copt903 * l0 * l1 +
                  copt1051 * copt1446 * copt744 * l0 * l2 +
                  copt1048 * copt1419 * copt582 * l1 * l2)) /
               2.;
  out2(4, 3) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt1603 * copt903 * l0 * l1 +
                  copt1051 * copt1574 * copt744 * l0 * l2 +
                  copt1048 * copt1523 * copt582 * l1 * l2)) /
               2.;
  out2(4, 4) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt1725 * copt903 * l0 * l1 +
                  copt1051 * copt1702 * copt744 * l0 * l2 +
                  copt1048 * copt1657 * copt582 * l1 * l2)) /
               2.;
  out2(4, 5) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt1847 * copt903 * l0 * l1 +
                  copt1051 * copt1823 * copt744 * l0 * l2 +
                  copt1048 * copt1774 * copt582 * l1 * l2)) /
               2.;
  out2(4, 6) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt1981 * copt903 * l0 * l1 +
                  copt1051 * copt1932 * copt744 * l0 * l2 +
                  copt1048 * copt1882 * copt582 * l1 * l2)) /
               2.;
  out2(4, 7) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt2107 * copt903 * l0 * l1 +
                  copt1051 * copt2066 * copt744 * l0 * l2 +
                  copt1048 * copt2014 * copt582 * l1 * l2)) /
               2.;
  out2(4, 8) = -(copt578 * copt579 * copt580 * copt581 *
                 (copt1054 * copt2220 * copt903 * l0 * l1 +
                  copt1051 * copt2181 * copt744 * l0 * l2 +
                  copt1048 * copt2136 * copt582 * l1 * l2)) /
               2.;
  out2(4, 9)  = -(copt1048 * copt2248 * copt578 * copt579 * copt582) / 2.;
  out2(4, 10) = -(copt1048 * copt2271 * copt578 * copt579 * copt582) / 2.;
  out2(4, 11) = -(copt1048 * copt2288 * copt578 * copt579 * copt582) / 2.;
  out2(4, 12) = -(copt1051 * copt2304 * copt578 * copt580 * copt744) / 2.;
  out2(4, 13) = -(copt1051 * copt2318 * copt578 * copt580 * copt744) / 2.;
  out2(4, 14) = -(copt1051 * copt2336 * copt578 * copt580 * copt744) / 2.;
  out2(4, 15) = -(copt1054 * copt2353 * copt578 * copt581 * copt903) / 2.;
  out2(4, 16) = -(copt1054 * copt2368 * copt578 * copt581 * copt903) / 2.;
  out2(4, 17) = -(copt1054 * copt2382 * copt578 * copt581 * copt903) / 2.;
  out2(5, 0) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt1350 * l0 * l1 + copt1062 * copt1262 * l0 * l2 +
         copt1059 * copt1244 * l1 * l2)) /
      2.;
  out2(5, 1) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt1402 * l0 * l1 + copt1062 * copt1370 * l0 * l2 +
         copt1059 * copt1366 * l1 * l2)) /
      2.;
  out2(5, 2) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt1476 * l0 * l1 + copt1062 * copt1446 * l0 * l2 +
         copt1059 * copt1419 * l1 * l2)) /
      2.;
  out2(5, 3) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt1603 * l0 * l1 + copt1062 * copt1574 * l0 * l2 +
         copt1059 * copt1523 * l1 * l2)) /
      2.;
  out2(5, 4) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt1725 * l0 * l1 + copt1062 * copt1702 * l0 * l2 +
         copt1059 * copt1657 * l1 * l2)) /
      2.;
  out2(5, 5) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt1847 * l0 * l1 + copt1062 * copt1823 * l0 * l2 +
         copt1059 * copt1774 * l1 * l2)) /
      2.;
  out2(5, 6) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt1981 * l0 * l1 + copt1062 * copt1932 * l0 * l2 +
         copt1059 * copt1882 * l1 * l2)) /
      2.;
  out2(5, 7) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt2107 * l0 * l1 + copt1062 * copt2066 * l0 * l2 +
         copt1059 * copt2014 * l1 * l2)) /
      2.;
  out2(5, 8) =
      -(copt578 * copt579 * copt580 * copt581 *
        (copt1065 * copt2220 * l0 * l1 + copt1062 * copt2181 * l0 * l2 +
         copt1059 * copt2136 * l1 * l2)) /
      2.;
  out2(5, 9)  = -(copt1059 * copt2248 * copt578 * copt579) / 2.;
  out2(5, 10) = -(copt1059 * copt2271 * copt578 * copt579) / 2.;
  out2(5, 11) = -(copt1059 * copt2288 * copt578 * copt579) / 2.;
  out2(5, 12) = -(copt1062 * copt2304 * copt578 * copt580) / 2.;
  out2(5, 13) = -(copt1062 * copt2318 * copt578 * copt580) / 2.;
  out2(5, 14) = -(copt1062 * copt2336 * copt578 * copt580) / 2.;
  out2(5, 15) = -(copt1065 * copt2353 * copt578 * copt581) / 2.;
  out2(5, 16) = -(copt1065 * copt2368 * copt578 * copt581) / 2.;
  out2(5, 17) = -(copt1065 * copt2382 * copt578 * copt581) / 2.;
  return std::make_tuple(grad, val);
}

#endif // hylc_strain_II
